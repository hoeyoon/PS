#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// strArr_len은 배열 strArr의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* strArr[], size_t strArr_len) {
    int answer = 0;
    int *n = (int*)malloc(sizeof(int) * 31);
    memset(n, 0, sizeof(int) * 31);
    for(int i = 0; i < strArr_len; i++){
        int len = strlen(strArr[i]);
        n[len]++;
    }
    int max = -1;
    for(int i = 0; i < 31; i++){
        if(max < n[i]){
            max = n[i];
        }
    }
    answer = max;
    return answer;
}