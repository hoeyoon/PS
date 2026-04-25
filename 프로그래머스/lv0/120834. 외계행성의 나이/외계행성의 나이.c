#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(int age) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int temp = age;
    int count = 0;
    while(temp > 0){
        count++;
        temp /= 10;
    }
    char* answer = (char*)malloc(sizeof(char) * count + 1);
    char *num = (char*)malloc(sizeof(char) * count + 1);
    char *p = answer;
    sprintf(num, "%d", age);
    while(*num != '\0'){
        if('0' <= *num && *num <= '9'){
            *p++ = *num - '0' + 'a';
        }
        num++;
    }
    *p = '\0';
    return answer;
}