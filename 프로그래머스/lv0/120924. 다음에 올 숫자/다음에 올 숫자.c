#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// common_len은 배열 common의 길이입니다.
int solution(int common[], size_t common_len) {
    int answer = 0;
    int n = common_len;
    if(common[n - 1] - common[n - 2] == common[n - 2] - common[n - 3]){
        answer = common[n - 1] + common[n - 1] - common[n - 2];
    }
    else if(common[n - 1] / common[n - 2] == common[n - 2] / common[n - 3]){
        answer = common[n - 1] * (common[n - 1] / common[n - 2]);
    }
    return answer;
}