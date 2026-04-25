#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* rsp) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(rsp);
    char* answer = (char*)malloc(sizeof(char) * len + 1);
    char *p = answer;
    while(*rsp != '\0'){
        if(*rsp == '2'){
            *p++ = '0';
        }
        else if(*rsp == '0'){
            *p++ = '5';
        }
        else if(*rsp == '5'){
            *p++ = '2';
        }
        rsp++;
    }
    *p = '\0';
    return answer;
}