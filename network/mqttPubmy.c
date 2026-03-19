#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "MQTTClient.h"

#define ADDRESS "tcp://163.152.213.120:1883"
#define CLIENTID "김도경"
#define TOPIC "school/test"

char username[50];

void printTime()
{
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    printf("[%02d:%02d:%02d] ", t->tm_hour, t->tm_min, t->tm_sec);
}

int messageArrived(void *context, char *topicName, int topicLen, MQTTClient_message *message)
{
    char buffer[256] = {0};
    memcpy(buffer, message->payload, message->payloadlen);

    char *name = strtok(buffer, "|");
    char *msg = strtok(NULL, "|");

    // 내가 보낸 메시지는 출력 안 하게 (선택)
    if (name && strcmp(name, username) == 0) {
        MQTTClient_freeMessage(&message);
        MQTTClient_free(topicName);
        return 1;
    }

    printTime();

    if (name && msg)
        printf("%s: %s\n", name, msg);
    else
        printf("%s\n", buffer);

    MQTTClient_freeMessage(&message);
    MQTTClient_free(topicName);
    return 1;
}

int main()
{
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;

    printf("닉네임 입력: ");
    scanf("%s", username);
    getchar(); // 개행 제거

    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);
    MQTTClient_setCallbacks(client, NULL, NULL, messageArrived, NULL);

    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;

    if (MQTTClient_connect(client, &conn_opts) != MQTTCLIENT_SUCCESS) {
        printf("연결 실패\n");
        return -1;
    }

    MQTTClient_subscribe(client, TOPIC, 1);

    printf("💬 채팅 시작! (종료: exit 입력)\n");

    while (1)
    {
        char input[200];
        fgets(input, sizeof(input), stdin);

        // 개행 제거
        input[strcspn(input, "\n")] = 0;

        if (strcmp(input, "exit") == 0)
            break;

        char message[256];
        sprintf(message, "%s|%s", username, input);

        pubmsg.payload = message;
        pubmsg.payloadlen = (int)strlen(message);
        pubmsg.qos = 1;
        pubmsg.retained = 0;

        MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token);
        MQTTClient_waitForCompletion(client, token, 1000);

        printTime();
        printf("나: %s\n", input);
    }

    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);

    return 0;
}