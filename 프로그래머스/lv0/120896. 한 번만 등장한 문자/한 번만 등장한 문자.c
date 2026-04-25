#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(s);
    char* answer = (char*)malloc(sizeof(char) * len);
    char *p = answer;
    int *apb = (int*)malloc(sizeof(int) * 26);
    memset(apb, 0, sizeof(int) * 26);
    while(*s != '\0'){
        if('a' <= *s && *s <= 'z'){
            apb[*s - 'a']++;
        }
        s++;
    }
    for(int i = 0; i < 26; i++){
        if(apb[i] == 1){
            *p++ = i + 'a';
        }
    }
    *p = '\0';
    return answer;
}