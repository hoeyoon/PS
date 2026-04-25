#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(my_string);
    char* answer = (char*)malloc(sizeof(char) * len + 1);
    strcpy(answer, my_string);
    char *p = answer;
    while(*p != '\0'){
        if('a' <= *p && *p <= 'z'){
            *p = *p - 'a' + 'A';
        }
        else if('A' <= *p && *p <= 'Z'){
            *p = *p - 'A' + 'a';
        }
        p++;
    }
    return answer;
}