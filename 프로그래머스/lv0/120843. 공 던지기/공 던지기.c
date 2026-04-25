#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int solution(int numbers[], size_t numbers_len, int k) {
    int answer = 0;
    int *num = (int*)malloc(sizeof(int) * numbers_len * k);
    for(int i = 0; i < k; i++){
        for(int j = 0; j < numbers_len; j++){
            num[i * numbers_len + j] = numbers[j];
        }
    }
    for(int i = 0; i < k - 1; i++){
        num += 2;
    }
    answer = *num;
    return answer;
}