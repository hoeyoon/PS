#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// dots_rows는 2차원 배열 dots의 행 길이, dots_cols는 2차원 배열 dots의 열 길이입니다.
int solution(int** dots, size_t dots_rows, size_t dots_cols) {
    int answer = 0;
    int max_x = -257, min_x = 257, max_y = -257, min_y = 257;
    for(int i = 0; i < dots_rows; i++){
        if(max_x < dots[i][0]){
            max_x = dots[i][0];
        }
        if(min_x > dots[i][0]){
            min_x = dots[i][0];
        }
        if(max_y < dots[i][1]){
            max_y = dots[i][1];
        }
        if(min_y > dots[i][1]){
            min_y = dots[i][1];
        }
    }
    answer = (max_x - min_x) * (max_y - min_y);
    
    return answer;
}