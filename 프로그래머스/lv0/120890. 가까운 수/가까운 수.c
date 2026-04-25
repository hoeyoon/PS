#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len, int n) {
    int answer = 0;
    int *num = (int*)malloc(sizeof(int) * array_len);
    for(int i = 0; i < array_len; i++){
        for(int j = 0; j < array_len; j++){
            if(array[i] < array[j]){
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    for(int i = 0; i < array_len; i++){
        num[i] = array[i] - n;
        if(num[i] < 0){
            num[i] = -num[i];
        }
    }
    int min = 101;
    for(int i = 0; i < array_len; i++){
        if(min > num[i]){
            min = num[i];
        }
    }
    int idx;
    for(int i = 0; i < array_len; i++){
        if(min == num[i]){
            idx = i;
            break;
        }
    }
    answer = array[idx];
    return answer;
}