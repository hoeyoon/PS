#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    char *token = strtok(s, " ");
    int temp = 0;
    while(token != NULL){
        answer += temp;
        if(strcmp(token, "Z") == 0){
            answer -= temp;
        }
        temp = atoi(token);
        token = strtok(NULL, " ");
    }
    answer += temp;
    return answer;
}