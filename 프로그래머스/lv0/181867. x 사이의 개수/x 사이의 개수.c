#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* myString) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(myString);
    int size = 0;
    for(int i = 0; i < len; i++){
        if(myString[i] == 'x'){
            size++;
        }
    }
    int* answer = (int*)malloc(sizeof(int) * (size + 1));
    int count = 0;
    int *p = answer;
    for(int i = 0; i < len; i++){
        if(myString[i] == 'x'){
            *p++ = count;
            count = 0;
        }
        else{
            count++;
        }
        if(i == len - 1){
            *p++ = count;
        }
    }
    return answer;
}