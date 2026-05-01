#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a = 0, b = 0;
    size_t pos = s.find("KOI");
    while((pos = s.find("KOI", pos)) != string::npos){
        a++;
        pos++;
    }
    pos = s.find("IOI");
    while((pos = s.find("IOI", pos)) != string::npos){
        b++;
        pos++;
    }
    cout << a << endl << b << endl;
    return 0;
}