#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(s);
    char* answer = (char*)malloc(sizeof(char) * len + 1);
    char *answer_p = answer;
    char *p = s;
    int count = 1;
    for(int i = 0; i < len; i++){
        if(*p == ' ' || *p == '\0'){
            *answer_p++ = *p++;
            count = 1;
            continue;
        }
        if(count % 2 == 1){
            if('a' <= *p && *p <= 'z'){
                *answer_p++ = *p++ - 32;
            }
            else{
                *answer_p++ = *p++;
            }
        }
        else if(count % 2 == 0){
            if('A' <= *p && *p <= 'Z'){
                *answer_p++ = *p++ + 32;
            }
            else{
                *answer_p++ = *p++;
            }
        }
        answer[len] = '\0';
        count++;
    }
    return answer;
}