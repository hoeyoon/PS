#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int chicken) {
    int answer = 0;
    int c = chicken;
    int temp;
    while(c >= 10){
        temp = c / 10;
        answer += temp;
        c = c % 10 + temp;
    }
    return answer;
}