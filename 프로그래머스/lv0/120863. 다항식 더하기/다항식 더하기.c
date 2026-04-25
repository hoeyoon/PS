#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* polynomial) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(sizeof(char) * 50);
    int len = strlen(polynomial);
    
    int s_num = 0, x_num = 0;
    int check = 0, num = 0;
    for(int i = 0; i < len; i++){
        if('0' <= polynomial[i] && polynomial[i] <= '9'){
            num = num * 10 + (polynomial[i] - '0');
            check = 1;
        }
        else if(polynomial[i] == 'x'){
            if(check == 1){
                x_num += num;
            }
            else{
                x_num += 1;
            }
            num = 0;
            check = 0;
        }
        else if(polynomial[i] == '+'){
            if(check == 1){
                s_num += num;
                num = 0;
                check = 0;
            }
        }
    }
    if(check == 1){
        s_num += num;
    }
    
    if(x_num > 0 && s_num > 0){
        if(x_num == 1){
            sprintf(answer, "x + %d", s_num);
        }
        else{
            sprintf(answer, "%dx + %d", x_num, s_num);
        }
    }
    else if(x_num > 0){
        if(x_num == 1){
            sprintf(answer, "x");
        }
        else{
            sprintf(answer, "%dx", x_num);
        }
    }
    else{
        sprintf(answer, "%d", s_num);
    }

    return answer;
}