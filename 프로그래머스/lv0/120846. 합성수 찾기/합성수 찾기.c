#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int c(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            count++;
        }
    }
    if(count > 2){
        return 1;
    }
    else{
        return 0;
    }
}

int solution(int n) {
    int answer = 0;
    for(int i = 1; i <= n; i++){
        if(c(i) == 1){
            answer++;
        }
    }
    return answer;
}