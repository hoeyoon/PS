#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n, int k) {
    int answer = 0;
    int count = 0;
    int temp = 1;
    while(temp <= n){
        if(temp % 10 == 0){
            count++;
        }
        temp++;
    }
    answer = 12000 * n + 2000 * k - 2000 * count;
    return answer;
}