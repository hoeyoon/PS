#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    int i;
    bool chk = false;
    for(i = 1; i <= n; i++){
        if(n % i == 0){
            cnt++;
        }
        if(cnt == k){
            chk = true;
            break;
        }
    }
    if(chk){
        cout << i << endl;
    }
    else{
        cout << 0 << endl;
    }
    return 0;
}