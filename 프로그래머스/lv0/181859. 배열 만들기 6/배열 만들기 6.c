#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int* solution(int arr[], size_t arr_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * arr_len);
    int *p = answer;
    int count = 0;
    for(int i = 0; i < arr_len; i++){
        if(count == 0 || answer[count - 1] != arr[i]){
            answer[count++] = arr[i];
        }
        else{
            count--;
        }
    }
    printf("%d", count);
    if(count == 0){
        free(answer);
        int *ar = (int*)malloc(sizeof(int));
        ar[0] = -1;
        return ar;
    }
    return answer;
}