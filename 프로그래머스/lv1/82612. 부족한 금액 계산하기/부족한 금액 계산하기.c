#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = -1;
    long long tmp = 0;
    for(int i = 0; i < count; i++){
        tmp += price * (i + 1);
    }
    answer = tmp - money;
    if(answer <= 0){
        answer = 0;
    }
    return answer;
}