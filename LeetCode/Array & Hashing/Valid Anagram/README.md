## **💻 문제 설명**
[문제설명](https://neetcode.io/problems/is-anagram/question)

**난이도 : Easy, 알고리즘 종류: Hash Table, String, Sorting**
```
유효한 애너그램 (Valid Anagram)
문제 설명:
두 개의 문자열 s와 t가 주어졌을 때, 두 문자열이 애너그램 관계이면 true를 반환하고, 그렇지 않으면 false를 반환하세요.

애너그램(Anagram)이란 한 문자열의 문자를 재배열하여 다른 문자열을 만들 수 있는 경우를 말합니다. 즉, 두 문자열은 동일한 문자를 정확히 같은 횟수만큼 포함하고 있어야 하며, 문자의 순서만 다를 수 있습니다.

예제 1:

입력: s = "racecar", t = "carrace"

출력: true

예제 2:

입력: s = "jar", t = "jam"

출력: false

제약 사항:

s와 t는 영어 소문자로만 구성됩니다.
```


## **💡 접근 및 설계**

s, t의 길이만큼 반복문을 돌려 문자의 개수를 저장하는 배열에 개수 설정 두 배열을 비교하여 개수가 다르면 false 리턴

### **✏️ 알고리즘 풀이**

#### 내 풀이
```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr1[26] = {0, };
        int arr2[26] = {0, };
        for(int i = 0; i < s.length(); i++){
            arr1[s[i] - 'a']++;
        }
        for(int i = 0; i < t.length(); i++){
            arr2[t[i] - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
};
```

#### 솔루션
```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
```
```plaintext
두 문자열의 길이가 같으면 false 리턴
두 문자열 정렬 후 두 문자열 비교
```

## **💭 오늘의 회고**
나는 문자의 개수를 세어 비교 했으나 솔루션은 문자열을 오름차순 정렬하여 두 문자열을 비교하였다.
정렬하는 것을 고려해보자