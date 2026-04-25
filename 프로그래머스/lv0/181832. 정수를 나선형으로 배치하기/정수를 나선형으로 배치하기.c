#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int** solution(int n) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int** answer = (int**)malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        answer[i] = (int*)malloc(sizeof(int) * n);
    }
    int num = 1;
    int sx = 0, ex = n - 1;
    int sy = 0, ey = n - 1;
    while(num <= n * n){
        for(int i = sy; i <= ey; ++i){
            answer[sx][i] = num++;
        }
        sx++;
        for(int i = sx; i <= ex; ++i){
            answer[i][ey] = num++;
        }
        ey--;
        for(int i = ey; i >= sy; --i){
            answer[ex][i] = num++;
        }
        ex--;
        for(int i = ex; i >= sx; --i){
            answer[i][sy] = num++;
        }
        sy++;
    }
    return answer;
}