#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int s, e;
    while(true){
        cin >> s >> e;
        if((2 <= s && s <= 9) && (2 <= e && e <= 9)){
            for(int i = 1; i <= 9; i++){
                if(s > e){
                    for(int j = s; j >= e; j--){
                        cout << j << " * " << i << " = " << setw(2) << j * i << "   ";
                    }
                }
                else{
                    for(int j = s; j <= e; j++){
                        cout << j << " * " << i << " = " << setw(2) << j * i << "   ";
                    }
                }
                cout << endl;
            }
            break;
        }
        else{
            cout << "INPUT ERROR!" << endl;
        }
    }
    return 0;
}