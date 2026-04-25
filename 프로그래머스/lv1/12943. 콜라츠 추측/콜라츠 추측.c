#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(long long num) {
    int answer = 0;
    int c = 0;
    while(num > 1){
        if(num % 2 == 0){
            num /= 2;
        }
        else{
            num = num * 3 + 1;
        }
        c++;
    }
    if(c >= 500){
        answer = -1;
    }
    else{
        answer = c;
    }
    return answer;
}