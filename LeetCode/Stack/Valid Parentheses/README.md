## **💻 문제 설명**
[문제링크](https://neetcode.io/problems/validate-parentheses/question)
### 유효한 괄호 (Valid Parentheses)
**난이도 : Easy, 알고리즘 종류: String, Stack**

'(', ')', '{', '}', '[' 그리고 ']' 문자로 구성된 문자열 `s`가 주어집니다.
다음의 조건을 모두 만족해야만 입력 문자열 `s`가 유효하다고 판단할 수 있습니다:

1. 모든 여는 괄호는 동일한 종류의 닫는 괄호로 닫혀야 합니다.
2. 여는 괄호는 반드시 올바른 순서대로 닫혀야 합니다.
3. 모든 닫는 괄호는 그에 상응하는 동일한 종류의 여는 괄호를 가지고 있어야 합니다.

`s`가 유효한 문자열이면 `true`를, 그렇지 않으면 `false`를 반환하세요.

---

**예시 1:**
* 입력: s = "[]"
* 출력: true

**예시 2:**
* 입력: s = "([{}])"
* 출력: true

**예시 3:**
* 입력: s = "[(])"
* 출력: false
* 설명: 괄호가 올바른 순서로 닫히지 않았습니다.

---

**제약 사항:**
* `1 <= s.length <= 1000`
* `s`는 오직 괄호 문자 `'()[]{}'`로만 구성되어 있습니다.


## **💡 접근 및 설계**
stack을 사용하고 문자가 (, {, [ 이면 스택에 넣는다.
), }, ] 이면 stack의 top값이 (, {, [ 이면 pop을 한다.
stack이 비었으면 true 비어있지 않으면 false를 리턴한다.


### **✏️ 알고리즘 풀이**
#### 나의 풀이 (Stack)
```c++
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
```
$$시간복잡도: O(n)$$
$$공간복잡도: O(n)$$

#### Brute Force
```c++
class Solution {
    public:
    bool isValid(string s) {
        while (true) {
            size_t pos = string::npos;
            if ((pos = s.find("()")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            if ((pos = s.find("{}")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            if ((pos = s.find("[]")) != string::npos) {
                s.erase(pos, 2);
                continue;
            }
            break;
        }
        return s.empty();
    }
};
```
```plaintext
(), {}, []를 찾으면 그것들을 문자열에서 지운다.
문자열이 비었으면 true 아니면 false를 리턴한다.
```
$$시간복잡도: O(n^2)$$
$$공간복잡도: O(n)$$

#### Stack
```c++
class Solution {
    public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (closeToOpen.count(c)) {
                if (!stack.empty() && stack.top() == closeToOpen[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
```
```plaintext
unordered_map을 사용해 모든 괄호를 저장한다.
(key: 닫힌 괄호, value: 열린 괄호)
문자열 s의 길이만큼 반복문을 돌리고
만약 c가 닫힌괄호라면
    만약 스택의 값이 존재하고 스택의 top의 값이 닫힌괄호의 value라면 스택에서 pop한다.
    아니라면 리턴한다.
아니라면 스택에 push한다.
반복문이 끝나고 스택이 비어있으면 true아니면 false 리턴한다.
```
$$시간복잡도: O(n)$$
$$공간복잡도: O(n)$$

## **💭 오늘의 회고**
Stack을 이용해서 풀었지만 솔루션의 코드와 내코드와 비교해보면 내코드는 뭔가 복잡해보인다.
unordered_map을 사용해서 좀 더 깔끔하게 코드를 작성할수 있다.