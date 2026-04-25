#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr1_len은 배열 arr1의 길이입니다.
// arr2_len은 배열 arr2의 길이입니다.
int solution(int arr1[], size_t arr1_len, int arr2[], size_t arr2_len) {
    int answer = 0;
    if(arr1_len < arr2_len){
        answer = -1;
    }
    else if(arr1_len > arr2_len){
        answer = 1;
    }
    else{
        int sum1 = 0, sum2 = 0;
        for(int i = 0; i < arr1_len; i++){
            sum1 += arr1[i];
        }
        for(int i = 0; i < arr2_len; i++){
            sum2 += arr2[i];
        }
        if(sum1 < sum2){
            answer = -1;
        }
        else if(sum1 > sum2){
            answer = 1;
        }
        else{
            answer = 0;
        }
    }
    return answer;
}