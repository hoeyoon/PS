#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int sum = 1;
    int i = 1;
    while(1){
        sum *= i;
        if(sum > n){
            answer = i - 1;
            break;
        }
        i++;
    }
    return answer;
}