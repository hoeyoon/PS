#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* A, const char* B) {
    int answer = 0;
    int lenA = strlen(A);
    int lenB = strlen(B);
    
    for(int i = 0; i < lenA; i++){
        char str[lenA + 1];
        for(int j = 0; j < lenA; j++){
            str[j] = A[(j - i + lenA) % lenA];
        }
        str[lenA] = '\0';
        if(strcmp(B, str) == 0){
            return i;
        }
    }
    return -1;
}