#include <iostream>
using namespace std;

long long fac(int n){
    if(n == 1){
        cout << "1! = 1" << endl;
        return 1;
    }
    else{
        cout << n << "! = " << n << " * " << n - 1 << "!" << endl;
        return  n * fac(n - 1);
    }
}

int main(){
    int n;
    long long answer = 0;

    cin >> n;
    answer = fac(n);
    cout << answer << endl;
    return 0;
}