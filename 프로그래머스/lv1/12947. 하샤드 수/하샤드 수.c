#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool solution(int x) {
    bool answer = true;
    int n = x;
    int a = 0;
    while(n > 0){
        a += n % 10;
        n /= 10;
    }
    if(x % a == 0){
        answer = true;
    }
    else{
        answer = false;
    }
    return answer;
}