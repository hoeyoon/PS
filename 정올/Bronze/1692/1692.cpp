#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int result = n * m;

    while(m > 0){
        cout << n * (m % 10) << endl;
        m /= 10;
    }
    cout << result << endl;
    return 0;
}