#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n * m; i++){
        if((i - 1) % m == 0){
            cout << endl;
        }
        cout << i << " ";
    }
    return 0;
}