#include <stdio.h>
#include <string.h>
#include "MQTTClient.h"

#define ADDRESS "tcp://163.152.213.104a:1883"
#define CLIENTID "dog0"
#define TOPIC "school/test"

int main()
{
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;

    char input[10];

    MQTTClient_create(&client, ADDRESS, CLIENTID, MQTTCLIENT_PERSISTENCE_NONE, NULL);

    if (MQTTClient_connect(client, &conn_opts) != MQTTCLIENT_SUCCESS)
    {
        printf("접속 실패!\n");
        return -1;
    }

    printf("문자 입력 (a: 강아지, b: 고양이, c: 토끼): ");
    fgets(input, sizeof(input), stdin);

    char *message;

    switch (input[0])
    {
    case 'a':
        message = " /\\_/\\\n( o.o )\n > ^ <\n"; // 강아지
        break;
    case 'b':
        message = " /\\_/\\\n( =^.^= )\n  (   )\n"; // 고양이
        break;
    case 'c':
        message = " (\\_/)\n ( •_•)\n />🥕\n"; // 토끼
        break;
    default:
        message = "잘못된 입력!\n";
        break;
    }

    pubmsg.payload = message;
    pubmsg.payloadlen = (int)strlen(message);
    pubmsg.qos = 1;

    MQTTClient_publishMessage(client, TOPIC, &pubmsg, NULL);

    printf("전송된 메시지:\n%s\n", message);

    MQTTClient_disconnect(client, 10000);
    MQTTClient_destroy(&client);
    return 0;
}