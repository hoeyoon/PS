#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            if(ch == '(' || ch == '{' || ch == '['){
                stack.push(ch);
            }
            else if(!stack.empty()){
                if((ch == ')' && stack.top() == '(') || 
                    (ch == '}' && stack.top() == '{') ||
                    (ch == ']' && stack.top() == '[')
                ){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        if(!stack.empty()){
            return false;
        }
        return true;
    }
};
