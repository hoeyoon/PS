#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n < 2){
        return false;
    }
    for(int i = 2; i <= n / i; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        if(isPrime(m)){
            cout << m << endl;
            continue;
        }
        bool chk = false;
        for(int j = 1; !chk; j++){
            if(isPrime(m - j)){
                cout << m - j << " ";
                chk = true;
            }
            if(isPrime(m + j)){
                cout << m + j << " ";
                chk = true;
            }
        }
        cout << endl;
    }
    return 0;
}