#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(my_string);
    char* answer = (char*)malloc(sizeof(char) * len);
    strcpy(answer, my_string);
    for(int i = 0; i < len / 2; i++){
        char temp = answer[i];
        answer[i] = answer[len - 1 - i];
        answer[len - 1 - i] = temp;
    }
    return answer;
}