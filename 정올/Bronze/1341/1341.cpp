#include <iostream>
#include <iomanip>
using namespace std;

void print(int i){
    for(int j = 1; j <= 9; j++){
        if((j - 1) % 3 == 0){
            cout << endl;
        }
        cout << i << " * " << j << " = " << setw(2) << i * j << "   ";
    }
    cout << endl;
}

int main(){
    int s, e;
    cin >> s >> e;
    if(s > e){
        for(int i = s; i >= e; i--){
            print(i);
        }
    }
    else{
        for(int i = s; i <= e; i++){
            print(i);
        }
    }
    return 0;
}