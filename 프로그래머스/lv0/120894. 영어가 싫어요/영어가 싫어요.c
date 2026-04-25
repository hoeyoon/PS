#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
long long solution(const char* numbers) {
    long long answer = 0;
    int len = strlen(numbers);
    char *num = (char*)malloc(sizeof(char) * len + 1);
    char *n = num;
    char *a = (char*)malloc(sizeof(char) * 6);
    char *p = a;
    for(int i = 0; i < len; i++){
        *p++ = numbers[i];
        *p = '\0';
        if(strcmp(a, "zero") == 0){
            *n++ = '0';
            p = a;
            *p = '\0';
        }
        else if(strcmp(a, "one") == 0){
            *n++ = '1';
            p = a;
            *p = '\0';
        }
        else if(strcmp(a, "two") == 0){
            *n++ = '2';
            p = a;
            *p = '\0';
        }
        else if(strcmp(a, "three") == 0){
            *n++ = '3';
            p = a;
            *p = '\0';
        }
        else if(strcmp(a, "four") == 0){
            *n++ = '4';
            p = a;
            *p = '\0';
        }
        else if(strcmp(a, "five") == 0){
            *n++ = '5';
            p = a;
            *p = '\0';
        }
        else if(strcmp(a, "six") == 0){
            *n++ = '6';
            p = a;
            *p = '\0';
        }
        else if(strcmp(a, "seven") == 0){
            *n++ = '7';
            p = a;
            *p = '\0';
        }
        else if(strcmp(a, "eight") == 0){
            *n++ = '8';
            p = a;
            *p = '\0';
        }
        else if(strcmp(a, "nine") == 0){
            *n++ = '9';
            p = a;
            *p = '\0';
        }
    }
    *n = '\0';
    answer = atoll(num);
    return answer;
}