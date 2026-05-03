#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n <= 50 && n % 2 == 1){
        for(int i = 0; i < n / 2 + 1; i++){
            for(int j = 0; j < i + 1; j++){
                cout << j + 1 << " ";
            }
            cout << endl;
        }
        for(int i = 1; i < n / 2 + 1; i++){
            for(int j = 0; j < (n / 2 + 1) - i; j++){
                cout << j + 1 << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "INPUT ERROR!" << endl;
    }
    return 0;
}