#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int check(char *s){
    int len = strlen(s);
    int count = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == '1'){
            count += pow(2, len - 1 - i);
        }
    }
    return count;
}

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* bin1, const char* bin2) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char) * 11);
    memset(answer, 0, sizeof(char) * 10 + 1);
    char *p = answer;
    int len = strlen(bin1);
    int a = check(bin1);
    int b = check(bin2);
    int sum = a + b;
    if(sum == 0){
        return "0";
    }
    while(sum > 0){
        if(sum % 2 == 1){
            *p++ = '1';
        }
        else{
            *p++ = '0';
        }
        sum /= 2;
    }
    *p = '\0';
    for(int i = 0; i < strlen(answer) / 2; i++){
        char temp = answer[i];
        answer[i] = answer[strlen(answer) - 1 - i];
        answer[strlen(answer) - 1 - i] = temp;
    }
    return answer;
}