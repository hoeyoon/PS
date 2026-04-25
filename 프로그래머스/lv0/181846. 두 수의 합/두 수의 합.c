#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* a, const char* b) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(a) > strlen(b) ? strlen(a) + 2 : strlen(b) + 2;
    char* answer = (char*)malloc(sizeof(char) * len);
    int a_len = strlen(a) - 1, b_len = strlen(b) - 1;
    int flag = 0;
    answer[--len] = '\0';
    int sum = 0;
    while(a_len >= 0 || b_len >= 0 || flag > 0){
        sum += flag;
        if(a_len >= 0){ 
            sum += (a[a_len--] - '0');
        }
        if(b_len >= 0){ 
            sum += (b[b_len--] - '0');
        }
        answer[--len] = sum % 10 + '0';
        flag = sum / 10;
        sum = 0;
    }
    answer = &answer[len];
    return answer;
}