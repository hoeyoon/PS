#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// indices_len은 배열 indices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string, int indices[], size_t indices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(my_string);
    char* answer = (char*)malloc(sizeof(char) * len + 1);
    int *tf = (int*)malloc(sizeof(int) * len);
    memset(tf, 0, sizeof(int) * len);
    int idx = 0;
    for(int i = 0; i < len; i++){
        if(idx == indices_len){
            break;
        }
        tf[indices[idx++]]++;
    }
    idx = 0;
    char *p = answer;
    for(int i = 0; i < len; i++){
        if(tf[idx++] != 1){
            *p++ = my_string[i];
        }
    }
    *p = '\0';
    return answer;
}