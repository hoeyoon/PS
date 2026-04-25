#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    long long num = n;
    int size = 0;
    while(num > 0){
        num /= 10;
        size++;
    }
    //printf("%d", size);
    int* answer = (int*)malloc(sizeof(long long) * (size + 1));
    int *p = answer;
    while(n > 0){
        *p++ = n % 10;
        n /= 10;
    }
    *p = '\0';
    return answer;
}