// #pragma once
#ifndef BASEBALLGAME_H
#define BASEBALLGAME_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 3

void generate_number(int *question);
void input_numbers(int *answer);
bool check_result(const int *question, const int *answer, int *strike, int *ball);

#endif // BASEBALLGAME_H