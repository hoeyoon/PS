#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int price) {
    int answer = 0;
    if(500000 <= price){
        price = price - price * (20.0 / 100.0);
    }
    else if(300000 <= price){
        price = price - price * (10.0 / 100.0);
    }
    else if(100000 <= price){
        price = price - price * (5.0 / 100.0);
    }
    answer = price;
    return answer;
}