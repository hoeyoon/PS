#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int a, int b) {
    int answer = 0;
    char a1[a];
    char b1[b];
    sprintf(a1, "%d", a);
    sprintf(b1, "%d", b);
    strcat(a1, b1);
    int r1 = atoi(a1);
    int r2 = 2 * a * b;
    //printf("%d %d", r1, r2);
    if(r1 == r2){
        answer = r1;
    }
    else if(r1 > r2){
        answer = r1;
    }
    else{
        answer = r2;
    }
    return answer;
}