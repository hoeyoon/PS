#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1000001

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* myString) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(sizeof(char*) * MAX);
    char *token = strtok(myString, "x");
    int i = 0;
    while(token != NULL){
        int len = strlen(token);
        if(len > 0){
            answer[i] = (char*)malloc(sizeof(char) * len + 1);
            strcpy(answer[i], token);
            i++;
        }
        token = strtok(NULL, "x");
    }
    int count = i;
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){
            if(strcmp(answer[i], answer[j]) < 0){
                char *temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }
    return answer;
}