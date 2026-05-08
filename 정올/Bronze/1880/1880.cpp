#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
    string encry;
    string str;

    cin >> encry;
    cin.ignore();
    getline(cin, str);

    for(int i = 0; i < str.size(); i++){
        if(isalpha(str[i])){
            if(islower(str[i])){
                cout << encry[str[i] - 'a'];
            }
            else{
                cout << (char)(toupper(encry[tolower(str[i]) - 'a']));
            }
        }
        else{
            cout << str[i];
        }
    }
    return 0;
}