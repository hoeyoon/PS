#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n <= 50 && n % 2 == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i * 2; j++){
                cout << " ";
            }
            for(int j = 0; j < (n - i) * 2 - 1; j++){
                cout << i << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "INPUT ERROR!" << endl;
    }
    return 0;
}