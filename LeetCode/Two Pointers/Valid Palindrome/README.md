## **💻 문제 설명**
[문제링크](https://neetcode.io/problems/is-palindrome/question?list=neetcode150)
```plaintext
유효한 팰린드롬 (Valid Palindrome)
문제 설명:
문자열 s가 주어졌을 때, 해당 문자열이 팰린드롬이면 true를 반환하고, 그렇지 않으면 false를 반환하세요.

팰린드롬(Palindrome)이란 앞뒤를 뒤집어도 똑같이 읽히는 문자열을 말합니다. 이 문제에서는 다음 두 가지 규칙을 따릅니다:

대소문자를 구분하지 않습니다. (Case-insensitive)

알파벳과 숫자(Alphanumeric)를 제외한 모든 문자는 무시합니다. (공백, 문장 부호 등 제외)

참고: 알파벳과 숫자란 문자 (A-Z, a-z)와 숫자 (0-9)를 의미합니다.

예제 1
입력: s = "Was it a car or a cat I saw?"

출력: true

설명: 알파벳과 숫자만 남기고 소문자로 변환하면 "wasitacaroracatisaw"가 됩니다. 이 문자열은 거꾸로 읽어도 동일하므로 팰린드롬입니다.

예제 2
입력: s = "tab a cat"

출력: false

설명: 공백을 제외하면 "tabacat"이 됩니다. 거꾸로 읽으면 "tacabat"이 되어 원래와 다르므로 팰린드롬이 아닙니다.

제약 사항:
1 <= s.length <= 1000

s는 출력 가능한 ASCII 문자로만 구성됩니다.
```

## **💡 접근 및 설계**
s에서 공백이나 특수문자를 없앤 문자열을 temp에 저장하고
앞의 값과 뒤의 값을 비교하여 팰린드롬이 아니라면 false 리턴 맞으면 true 리턴

### **✏️ 알고리즘 풀이**
#### 나의 풀이
```c++
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
```
$$시간복잡도: O(n)$$
$$공간복잡도: O(n)$$

#### 역 문자열 풀이
```c++
class Solution {
public:
    bool isPalindrome(string s) {
        string newStr = "";
        for (char c : s) {
            if (isalnum(c)) {
                newStr += tolower(c);
            }
        }
        return newStr == string(newStr.rbegin(), newStr.rend());
    }
};
```
```plaintext
역방향 반복자(rbegin(), rend())를 사용하여 true, false 리턴
```
$$시간복잡도: O(n)$$
$$공간복잡도: O(n)$$

#### 투 포인터 풀이
```c++
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;

        while (l < r) {
            while (l < r && !alphaNum(s[l])) {
                l++;
            }
            while (r > l && !alphaNum(s[r])) {
                r--;
            }
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }
            l++; r--;
        }
        return true;
    }

    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};
```
```plaintext
왼쪽 포인터 l, 오른쪽 포인터 r
l이 유효한 문자를 만날 때 까지 오른쪽으로 이동
r이 유효한 문자를 만날 때 까지 왼쪽으로 이동
만약 s[l] == s[r]이면 false리턴
반복문이 끝나면 true 리턴
```

$$시간복잡도: O(n)$$
$$공간복잡도: O(1)$$

## **💭 오늘의 회고**
나는 문자열을 조건에 맞게 정리한 다음 풀었는데 솔루션에서는
두 개의 포인터를 만들고 원본 문자열에서 직접 비교 하였다.
투포인터를 사용한 방식이 공간복잡도가 더 유리했다.