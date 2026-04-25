#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// emergency_len은 배열 emergency의 길이입니다.
int* solution(int emergency[], size_t emergency_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * emergency_len);
    int *num = (int*)malloc(sizeof(int) * emergency_len);
    int *p = answer;
    for(int i = 0; i < emergency_len; i++){
        num[i] = emergency[i];
    }
    for(int i = 0; i < emergency_len; i++){
        for(int j = 0; j < emergency_len; j++){
            if(num[i] > num[j]){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    for(int i = 0; i < emergency_len; i++){
        for(int j = 0; j < emergency_len; j++){
            if(emergency[i] == num[j]){
                *p++ = j + 1;
                break;
            }
        }
    }
    return answer;
}