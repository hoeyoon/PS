#include <iostream>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++){
        if(i % 2 == 0){
            for(int j = 1; j <= m; j++){
                cout << i * m + j << " ";
            }
        }
        else{
            for(int j = m; j >= 1; j--){
                cout << i * m + j << " ";
            }
        }
        cout << endl;
    }
    return 0;
}