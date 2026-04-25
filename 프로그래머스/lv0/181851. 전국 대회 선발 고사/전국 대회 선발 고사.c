#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// rank_len은 배열 rank의 길이입니다.
// attendance_len은 배열 attendance의 길이입니다.
int solution(int rank[], size_t rank_len, bool attendance[], size_t attendance_len) {
    int answer = 0;
    int count = 0;
    int *num = (int*)malloc(sizeof(int) * rank_len);
    int *p = num;
    int *idx = (int*)malloc(sizeof(int) * rank_len);
    int *p1 = idx;
    for(int i = 0; i < rank_len; i++){
        if(attendance[i] == true){
            *p1++ = i;
            *p++ = rank[i];
            count++;
        }
    }
    for(int i = 0; i < count; i++){
        for(int j = 0; j < count; j++){
            if(num[i] < num[j]){
                int temp = num[i];
                num[i] = num[j];
                num[j] = temp;
                int temp1 = idx[i];
                idx[i] = idx[j];
                idx[j] = temp1;
            }
        }
    }
    answer = 10000 * idx[0] + 100 * idx[1] + idx[2];
    return answer;
}