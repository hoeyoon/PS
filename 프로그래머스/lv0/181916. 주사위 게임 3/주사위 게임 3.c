#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int solution(int a, int b, int c, int d) {
    int answer = 0;
    int num[4] = {a, b, c, d};
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(num[i] < num[j]){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
    }
    if(num[0] == num[3]){
        return 1111 * num[0];
    }
    else if(num[0] == num[1] && num[2] == num[3]){
        return (num[0] + num[2]) * abs(num[0] - num[2]);
    }
    else if(num[1] == num[2] && (num[0] == num[1] || num[2] == num[3])){
        return pow(10 * num[1] + (num[0] != num[1] ? num[0] : num[3]), 2);
    }
    else if(num[0] != num[1] && num[1] != num[2] && num[2] != num[3]){
        return num[0];
    }
    else{
        return num[0] == num[1] ? num[2] * num[3] : (num[1] == num[2] ? num[0] * num[3] : num[0] * num[1]);
        }
}