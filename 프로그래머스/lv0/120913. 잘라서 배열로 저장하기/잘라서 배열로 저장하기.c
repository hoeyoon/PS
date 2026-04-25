#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_str, int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(my_str);
    int c;
    if(len % n == 0){
        c = len / n;
    }
    else{
        c = len / n + 1;
    }
    char** answer = (char**)malloc(sizeof(char*) * c);
    for(int i = 0; i < c; i++){
        answer[i] = (char*)malloc(sizeof(char) * n + 1);
        char *p = answer[i];
        int j = 0;
        while(*my_str != '\0'){
            if(j == n){
                break;
            }
            *p++ = *my_str;
            *p = '\0';
            j++;
            my_str++;
        }
    }
    
    return answer;
}