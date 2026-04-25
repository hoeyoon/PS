#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int num, int k) {
    int answer = -1;
    int count = 0;
    int temp = num;
    while(temp > 0){
        count++;
        temp /= 10;
    }
    char *n = (char*)malloc(sizeof(char) * count + 1);
    sprintf(n, "%d", num);
    int len = strlen(n);
    for(int i = 0; i < len; i++){
        if(n[i] - '0' == k){
            answer = i + 1;
            break;
        }
    }
    return answer;
}