#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// array_len은 배열 array의 길이입니다.
int solution(int array[], size_t array_len) {
    int answer = 0;
    char *num = (char*)malloc(sizeof(char) * array_len * array_len);
    for(int i = 0; i < array_len; i++){
        sprintf(num, "%d", array[i]);
        char *p = num;
        while(*p != '\0'){
            if(*p == '7'){
                answer++;
            }
            p++;
        }
    }
    printf("%s", num);
    return answer;
}