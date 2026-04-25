#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int i, int j, int k) {
    int answer = 0;
    char *n = (char*)malloc(sizeof(char) * i * j);
    for(int q = i; q <= j; q++){
        sprintf(n, "%d", q);
        for(int s = 0; s < strlen(n); s++){
            if(n[s] == (k + '0')){
                answer++;
            }
        }
    }
    return answer;
}