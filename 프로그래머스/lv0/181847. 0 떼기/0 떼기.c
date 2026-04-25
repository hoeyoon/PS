#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* n_str) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(n_str);
    char* answer = (char*)malloc(sizeof(char) * len + 1);
    char *p = answer;
    while(*n_str != '\0'){
        if(*n_str != '0'){
            break;
        }
        n_str++;
    }
    while(*n_str != '\0'){
        *p++ = *n_str;
        n_str++;
    }
    *p = '\0';
    return answer;
}