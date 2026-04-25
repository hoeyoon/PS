#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* my_string) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(my_string);
    int count = 0;
    for(int i = 0; i < len; i++){
        if(my_string[i] == ' '){
            count++;
        }
    }
    count++;
    char** answer = (char**)malloc(sizeof(char*) * count);
    for(int i = 0; i < count; i++){
        answer[i] = (char*)malloc(sizeof(char) * len + 1);
    }
    int idx_i = 0, idx_j = 0;
    for(int i = 0; i < len; i++){
        if(my_string[i] == ' '){
            idx_i++;
            idx_j = 0;
            continue;
        }
        answer[idx_i][idx_j++] = my_string[i];
        answer[idx_i][idx_j] = '\0';
    }
    
    return answer;
}