#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define max(a, b) (a > b) ? a : b

int cat(int a, int b){
    int i = 1;
    while(i <= b){
        i *= 10;
    }
    return (a * i) + b;
}

int solution(int a, int b) {
    int answer = 0;
    int ab = cat(a, b);
    int ba = cat(b, a);
    answer = max(ab, ba);
    return answer;
}