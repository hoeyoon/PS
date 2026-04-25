#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void lower(char *s){
    while(*s != '\0'){
        if('A' <= *s && *s <= 'Z'){
            *s = *s - 'A' + 'a';
        }
        s++;
    }
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* myString, const char* pat) {
    int answer = 0;
    int len1 = strlen(myString);
    int len2 = strlen(pat);
    char *str1 = (char*)malloc(sizeof(char) * len1 + 1);
    char *str2 = (char*)malloc(sizeof(char) * len2 + 1);
    strcpy(str1, myString);
    strcpy(str2, pat);
    if(len1 < len2){
        answer = 0;
    }
    else{
        lower(str1);
        lower(str2);
        if(strstr(str1, str2)){
            answer = 1;
        }
        else{
            answer = 0;
        }
    }
    return answer;
}