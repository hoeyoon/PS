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
    int m, n;
    cin >> m >> n;
    int sum = 0;
    int min = 10001;
    for(int i = m; i <= n; i++){
        if(isPrime(i)){
            if(min > i){
                min = i;
            }
            sum += i;
        }
    }
    if(sum == 0 && min == 10001){
        cout << -1 << endl;
    }
    else{
        cout << sum << endl << min << endl;
    }
    return 0;
}