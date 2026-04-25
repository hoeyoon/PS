#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// board_rows는 2차원 배열 board의 행 길이, board_cols는 2차원 배열 board의 열 길이입니다.
int solution(int** board, size_t board_rows, size_t board_cols) {
    int answer = 0;
    int n = board_rows;
    int arr[100][100] = {0, };
    int arr_x[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int arr_y[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 1){
                for(int k = 0; k < 9; k++){
                    int temp_x = i + arr_x[k];
                    int temp_y = j + arr_y[k];
                    if(0 <= temp_x && temp_x < n && 0 <= temp_y && temp_y < n){
                        arr[temp_x][temp_y] = 1;
                    }
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 0){
                answer++;
            }
        }
    }
    return answer;
}