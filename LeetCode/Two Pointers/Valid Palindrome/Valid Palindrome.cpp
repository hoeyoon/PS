#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(int i = 0; i < s.size(); i++){
            if(isalpha(s[i]) || isdigit(s[i])){
                temp.push_back(tolower(s[i]));
            }
        }
        int len = temp.size();
        for(int i = 0; i < len / 2; i++){
            if(temp[i] != temp[len - i - 1]){
                return false;
            }
        }
        return true;
    }
};
