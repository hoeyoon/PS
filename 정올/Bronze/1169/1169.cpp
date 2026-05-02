#include <iostream>
using namespace std;

int n;
int dice[10];
bool chk[10];

void print(){
    for(int i = 0; i < n; i++){
        cout << dice[i] << " ";
    }
    cout << endl;
}

void type_1(int cnt){
    if(cnt == n){
        print();
        return;
    }
    for(int i = 1; i <= 6; i++){
        dice[cnt] = i;
        type_1(cnt + 1);
    }
}

void type_2(int cnt, int start){
    if(cnt == n){
        print();
        return;
    }
    for(int i = start; i <= 6; i++){
        dice[cnt] = i;
        type_2(cnt + 1, i);
    }
}
void type_3(int cnt){
    if(cnt == n){
        print();
        return;
    }
    for(int i = 1; i <= 6; i++){
        if(chk[i]){
            continue;
        }
        chk[i] = true;
        dice[cnt] = i;
        type_3(cnt + 1);
        chk[i] = false;
    }
}

int main(){
    int type;
    cin >> n >> type;
    switch(type){
        case 1:
            type_1(0);
            break;
        case 2:
            type_2(0, 1);
            break;
        case 3:
            type_3(0);
            break;
    }
    return 0;
}