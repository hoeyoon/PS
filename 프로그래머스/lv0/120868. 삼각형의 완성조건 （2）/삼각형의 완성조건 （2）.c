#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define min(a, b) (a < b) ? a : b

// sides_len은 배열 sides의 길이입니다.
int solution(int sides[], size_t sides_len) {
    int answer = 0;
    int n = min(sides[0], sides[1]);
    answer = n * 2 - 1;
    return answer;
}