#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// included_len은 배열 included의 길이입니다.
int solution(int a, int d, bool included[], size_t included_len) {
    int answer = 0;
    int n[included_len];
    n[0] = a;
    for(int i = 1; i < included_len; i++){
        n[i] = n[i - 1] + d;
    }
    for(int i = 0; i < included_len; i++){
        if(included[i] == true){
            answer += n[i];
        }
    }
    return answer;
}