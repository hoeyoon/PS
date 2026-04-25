#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* binomial) {
    int answer = 0;
    int len = strlen(binomial);
    char **num = (char**)malloc(sizeof(char*) * len);
    char ch;
    for(int i = 0; i < 2; i++){
        num[i] = (char*)malloc(sizeof(char) * len + 1);
        char *p = num[i];
        while(*binomial != '\0'){
            if('0' <= *binomial && *binomial <= '9'){
                *p++ = *binomial;
            }
            if('*' <= *binomial && *binomial <= '-'){
                ch = *binomial;
                binomial++;
                break;
            }
            *p = '\0';
            binomial++;
        }
    }
    int a = atoi(num[0]);
    int b = atoi(num[1]);
    if(ch == '+'){
        answer = a + b;
    }
    else if(ch == '-'){
        answer = a - b;
    }
    else if(ch == '*'){
        answer = a * b;
    }
    return answer;
}