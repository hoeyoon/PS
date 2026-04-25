#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * k + 1);
    memset(answer, -1, sizeof(int) * k + 1);
    int *check = (int*)malloc(sizeof(int) * 100002);
    memset(check, 0, sizeof(int) * 100002);
    int idx = 0;
    for(int i = 0; i < arr_len; i++){
        if(check[arr[i]] == 1){
            continue;
        }
        check[arr[i]] = 1;
        answer[idx++] = arr[i];
        if(idx == k){
            break;
        }
    }
    return answer;
}