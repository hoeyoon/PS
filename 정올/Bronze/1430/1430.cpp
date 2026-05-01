#include <iostream>
using namespace std;

int main(){
    int arr[10] = {0, };
    int a, b, c;
    cin >> a >> b >> c;
    int n = a * b * c;
    while(n > 0){
        arr[n % 10]++;
        n /= 10;
    }
    for(int i = 0; i < 10; i++){
        cout << arr[i] << endl;
    }
    return 0;
}