#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numLog_len은 배열 numLog의 길이입니다.
char* solution(int numLog[], size_t numLog_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char) * numLog_len + 1);
    int n = numLog_len - 1;
    char *p = answer;
    int *n1 = numLog;
    int *n2 = numLog + 1;
    while(n-- > 0){
        if((*n2 - *n1) == 1){
            *p++ = 'w';
        }
        else if((*n2 - *n1) == -1){
            *p++ = 's';
        }
        else if((*n2 - *n1) == 10){
            *p++ = 'd';
        }
        else if((*n2 - *n1) == -10){
            *p++ = 'a';
        }
        n1++;
        n2++;
    }
    *p = '\0';
    return answer;
}