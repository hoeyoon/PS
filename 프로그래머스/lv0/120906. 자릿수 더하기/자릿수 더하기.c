#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(int n) {
    int answer = 0;
    int temp = n;
    int count = 0;
    while(temp > 0){
        count++;
        temp /= 10;
    }
    char *num = (char*)malloc(sizeof(char) * count + 1);
    sprintf(num, "%d", n);
    while(*num != '\0'){
        if('0' <= *num && *num <= '9'){
            answer += *num - '0';
        }
        num++;
    }
    return answer;
}