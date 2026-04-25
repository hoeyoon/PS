#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int pizza = 6;
    while(pizza % n != 0){
        pizza += 6;
    }
    answer = pizza / 6;
    return answer;
}