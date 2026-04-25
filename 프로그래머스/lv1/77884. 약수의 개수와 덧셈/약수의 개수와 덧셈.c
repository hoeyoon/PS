#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int left, int right) {
    int answer = 0;
    for(int i = left; i <= right; i++){
        int c = 0;
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                c++;
            }
        }
        if(c % 2 != 0){
            answer += -1 * i;
        }
        else{
            answer += i;
        }
    }
    return answer;
}