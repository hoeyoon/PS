#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 2;
    for(int i = 1; i <= 1000000; i++){
        if(i * i == n){
            return 1;
        }
    }
    return answer;
}