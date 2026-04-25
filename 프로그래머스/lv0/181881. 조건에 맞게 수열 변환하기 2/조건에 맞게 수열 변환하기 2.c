#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
    
// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    int answer = 0;
    int *arr1 = (int*)malloc(sizeof(int) * arr_len);
    int count = 0;
    while(1){
        for(int i = 0; i < arr_len; i++){
            arr1[i] = arr[i];
        }
        for(int i = 0; i < arr_len; i++){
            if(arr[i] >= 50 && arr[i] % 2 == 0){
                arr[i] /= 2;
            }
            else if(arr[i] < 50 && arr[i] % 2 == 1){
                arr[i] = arr[i] * 2 + 1;
            }
        }
        count++;
        int s = 0;
        for(int i = 0; i < arr_len; i++){
            if(arr[i] == arr1[i]){
                s++;
            }
            if(s == arr_len){
                return count - 1;
            }
        }
    }
}