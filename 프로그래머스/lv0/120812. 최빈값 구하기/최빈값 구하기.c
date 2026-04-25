#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int answer = 0;
    int *num = (int*)malloc(sizeof(int) * 1000);
    memset(num, 0, sizeof(int) * 1000);
    for(int i = 0; i < array_len; i++){
        num[array[i]]++;
    }
    int max = 0;
    int idx;
    for(int i = 0; i < 1000; i++){
        if(max < num[i]){
            max = num[i];
            idx = i;
        }
    }
    int count = 0;
    for(int i = 0; i < 1000; i++){
        if(max == num[i]){
            count++;
        }
    }
    if(count != 1){
        answer = -1;
    }
    else{
        answer = idx;
    }
    return answer;
}