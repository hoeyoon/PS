#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* myStr) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(myStr);
    int count= 0;
    for(int i = 0; i < len; i++){
        if(myStr[i] == 'a' || myStr[i] == 'b' || myStr[i] == 'c'){
            count++;
        }
    }
    char** answer = (char**)malloc(sizeof(char*) * count);
    int idx = 0;
    int idx_a = 0;
    char *str = (char*)malloc(sizeof(char) * len + 1);
    while(*myStr != '\0'){
        if(*myStr == 'a' || *myStr == 'b' || *myStr == 'c'){
            if(idx > 0){
                str[idx] = '\0';
                answer[idx_a] = (char*)malloc(sizeof(char) * len + 1);
                strcpy(answer[idx_a], str);
                idx = 0;
                idx_a++;
            }
        }
        else{
            str[idx++] = *myStr;
        }
        myStr++;
    }
    if(idx > 0){
        str[idx] = '\0';
        answer[idx_a] = (char*)malloc(sizeof(char) * len + 1);
        strcpy(answer[idx_a], str);
        idx = 0;
        idx_a++;
    }
    if(idx_a == 0){
        answer[0] = (char*)malloc(sizeof(char) * len + 1);
        strcpy(answer[0], "EMPTY");
        answer[1] = NULL;
    }
    return answer;
}