#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// picture_len은 배열 picture의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char *picture[], size_t picture_len, int k) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(sizeof(char*) * k * picture_len);
    for(int i = 0; i < k * picture_len; i++){
        int len = strlen(picture[i / k]) * k + 1;
        answer[i] = (char*)malloc(sizeof(char) * len);
        char *p = answer[i];
        for(int j = 0; j < len / k; j++){
            for(int u = 0; u < k; u++){
              *p++ = picture[i / k][j];
            }
        }
        *p = '\0';
    }
    return answer;
}