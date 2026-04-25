#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* my_string, const char* is_suffix) {
    int answer = 0;
    int len = strlen(my_string);
    char **words = (char**)malloc(sizeof(char*) * len + 1);
    int count = 0;
    for(int i = 0; i < len; i++){
        char *word = (char*)malloc(sizeof(char) * len + 1);
        int idx = 0;
        for(int j = i; j < len; j++){
            word[idx++] = my_string[j];
        }
        word[idx] = '\0';
        words[count++] = word;
    }
    for(int i = 0; i < len; i++){
        printf("%s\n", words[i]);
    }
    for(int i = 0; i < len; i++){
        if(strcmp(words[i], is_suffix) == 0){
            answer = 1;
            break;
        }
        else{
            answer = 0;
        }
    }
    return answer;
}