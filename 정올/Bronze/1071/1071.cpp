#include <iostream>
using namespace std;

int main(){
    int n;
    int m;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> m;
    int div = 0, mul = 0;
    for(int i = 0; i < n; i++){
        if(m % arr[i] == 0){
            div += arr[i];
        }
        if(arr[i] % m == 0){
            mul += arr[i];
        }
    }
    cout << div << endl << mul << endl;
    return 0;
}