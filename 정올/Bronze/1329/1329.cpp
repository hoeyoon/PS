#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n;
    if((1 <= n && n <= 100) && n % 2 == 1){
        for(int i = 0; i < n / 2 + 1; i++){
            for(int j = 0; j < i; j++){
                cout << " ";
                k = i;
            }
            for(int j = 0; j < i * 2 + 1; j++){
                cout << "*";
            }
            cout << endl;
        }
        for(int i = 1; i < n / 2 + 1; i++){
            for(int j = 0; j < k - 1; j++){
                cout << " ";
            }
            for(int j = 0; j < (n / 2 - i) * 2 + 1; j++){
                cout << "*";
            }
            k--;
            cout << endl;
        }
    }
    else{
        cout << "INPUT ERROR!" << endl;
    }
    return 0;
}