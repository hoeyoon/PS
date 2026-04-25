#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max(a, b) (a > b) ? a : b

// num_list_len은 배열 num_list의 길이입니다.
int solution(int num_list[], size_t num_list_len) {
    int answer = 0;
    int evennum = 0;
    int oddnum = 0;
    for(int i = 0; i < num_list_len; i++){
        if(i % 2 == 0){
            oddnum += num_list[i];
        }
        else{
            evennum += num_list[i];
        }
    }
    answer = max(oddnum, evennum);
    return answer;
}