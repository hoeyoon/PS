#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    int sum1 = 1, sum2 = 0;
    for(int i = 0; i < num_list_len; i++){
        sum1 *= num_list[i];
        sum2 += num_list[i];
    }
    sum2 *= sum2;
    if(sum1 < sum2){
        return 1;
    }
    return answer;
}