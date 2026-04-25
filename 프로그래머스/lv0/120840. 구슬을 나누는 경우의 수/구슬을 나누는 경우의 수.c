#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int balls, int share) {
    long long answer = 1;
    for(int i = 1; i <= share; i++){
        answer = (answer * balls) / i;
        balls--;
    }
    return answer;
}