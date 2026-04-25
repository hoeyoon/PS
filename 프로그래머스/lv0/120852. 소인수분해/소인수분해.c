#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int prime(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            count++;
        }
    }
    if(count == 2){
        return 1;
    }
    else{
        return 0;
    }
}

int* solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * n);
    int *p = answer;
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            if(prime(i) == 1){
                *p++ = i;
            }
        }
    }
    return answer;
}