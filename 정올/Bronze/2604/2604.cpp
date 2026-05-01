#include <iostream>
using namespace std;

int main(){
    string str;
    cin >> str;
    int answer = 10;
    for(int i = 1; i < str.length(); i++){
        if(str[i] == str[i - 1]){
            answer += 5;
        }
        else{
            answer += 10;
        }
    }
    cout << answer << endl;
    return 0;
}