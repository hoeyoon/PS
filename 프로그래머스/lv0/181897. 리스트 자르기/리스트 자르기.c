#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// slicer_len은 배열 slicer의 길이입니다.
// num_list_len은 배열 num_list의 길이입니다.
int* solution(int n, int slicer[], size_t slicer_len, int num_list[], size_t num_list_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * num_list_len * 4);
    int *p = answer;;
    if(n == 1){
        for(int i = 0; i <= slicer[1]; i++){
            *p++ = num_list[i];
        }
    }
    else if(n == 2){
        for(int i = slicer[0]; i <= num_list_len; i++){
            *p++ = num_list[i];
        }
    }
    else if(n == 3){
        for(int i = slicer[0]; i <= slicer[1]; i++){
            *p++ = num_list[i];
        }
    }
    else if(n == 4){
        for(int i = slicer[0]; i <= slicer[1]; i+=slicer[2]){
            *p++ = num_list[i];
        }
    }
    return answer;
}