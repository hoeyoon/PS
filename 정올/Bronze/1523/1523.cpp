#include <iostream>
using namespace std;

void print_1(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void print_2(int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void print_3(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        for(int j = 0; j < i * 2 + 1; j++){
            cout << "*";
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    if(n <= 100 && (1 <= m && m <= 3)){
        switch(m){
            case 1:
                print_1(n);
                break;
            case 2:
                print_2(n);
                break;
            case 3:
                print_3(n);
                break;
        }
    }
    else{
        cout << "INPUT ERROR!" << endl;
    }
    return 0;
}