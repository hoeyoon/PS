#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sides_len은 배열 sides의 길이입니다.
int solution(int sides[], size_t sides_len) {
    int answer = 0;
    for(int i = 0; i < sides_len; i++){
        for(int j = 0; j < sides_len; j++){
            if(sides[i] < sides[j]){
                int temp = sides[i];
                sides[i] = sides[j];
                sides[j] = temp;
            }
        }
    }
    if(sides[2] < sides[0] + sides[1]){
        return 1;
    }
    else{
        return 2;
    }
    return answer;
}