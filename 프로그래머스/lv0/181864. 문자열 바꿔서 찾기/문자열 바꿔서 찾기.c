#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* myString, const char* pat) {
    int answer = 0;
    int len = strlen(myString);
    char *str = (char*)malloc(sizeof(char) * len + 1);
    strcpy(str, myString);
    char *p = str;
    while(*p != '\0'){
        if(*p == 'A'){
            *p += 1;
        }
        else if(*p == 'B'){
            *p -= 1;
        }
        p++;
    }
    if(strstr(str, pat)){
        answer = 1;
    }
    else{
        answer = 0;
    }
    return answer;
}