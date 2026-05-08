#include <iostream>
#include <string>
using namespace std;

int main(){
    string str[5];
    int max = -1;
    for(int i = 0; i < 5; i++){
        cin >> str[i];
        int len = str[i].size();
        if(max < len){
            max = len;
        }
    }
    for(int i = 0; i < max; i++){
        for(int j = 0; j < 5; j++){
            if(i < str[j].size()){
                cout << str[j][i];
            }
        }
    }
    return 0;
}