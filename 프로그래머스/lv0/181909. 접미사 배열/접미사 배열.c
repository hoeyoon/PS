#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(my_string);
    int count = 0;
    char** answer = (char**)malloc(sizeof(char*) * len + 2);
    for(int i = 0; i < len; i++){
        int idx = 0;
        char *word = (char*)malloc(sizeof(char) * len + 2);
        for(int j = i; j < len; j++){
            word[idx++] = my_string[j];
        }
        word[idx] = '\0';
        answer[count++] = word; 
    }
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(strcmp(answer[i], answer[j]) < 0){
                char *temp = answer[i];
                answer[i] = answer[j];
                answer[j] = temp;
            }
        }
    }
    return answer;
}