#include <iostream>
using namespace std;

int main(){
    unsigned int n;
    for(int i = 0; i < 10; i++){
        bool k = false;
        cin >> n;
        if(n == 0){
            break;
        }
        int answer = 0;
        while(n > 0){
            if(n % 10 != 0){
                k = true;
            }
            if(k == true){
                cout << n % 10;
            }
            answer += n % 10;
            n /= 10;
        }
        cout << " " << answer << endl;
    }
    return 0;
}