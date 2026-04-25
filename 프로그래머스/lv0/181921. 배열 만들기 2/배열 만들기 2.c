#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int l, int r) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * r);
    *answer = 0;
    int *p = answer;
    int check = 1;
    if(*p == '\0'){
        *p = -1;
    }
    for(int i = l; i <= r; i++){
        int temp = i;
        check = 1;
        while(temp > 0){
            int n = temp % 10;
            if(n != 0 && n != 5){
                check = 0;
                break;
            }
            temp /= 10;
        }
        if(check == 1){
            *p++ = i;
        }
    }
    
    return answer;
}