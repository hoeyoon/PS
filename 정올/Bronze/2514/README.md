## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/2514?cursor=Niw0LDE=)

### 문제

주어진 문자열에서 연속 3개의 문자가 IOI 이거나 KOI인 문자열이 각각 몇 개 있는지 찾는 프로그램을 작성하라.  
문자열은 알파벳의 대문자로만 이루어진다.  
예를 들어 "KOIOIOI"라는 문자열은 KOI 1개 , IOI 2개가 포함되어있다.

![](https://u.jungol.co.kr/problem/2514/4794a6be-f089-4959-b141-09598d5858d1.png)

### 입력
입력은 한 줄이며 10,000자 이하의 알파벳 대문자로 구성된다.

### 출력
출력은 2줄이며, 첫 번째 줄에는 KOI의 개수, 두 번째 줄에는 IOI의 개수를 각각 출력하라.


#### 예제 #1
**입력**
```plaintext
KOIOIOI
```
**출력**
```plaintext
1 
2
```

#### 예제 #2
**입력**
```plaintext
KORKDIOIDXHKOIOIOIOPKOI
```
**출력**
```plaintext
2 
3
```

## **💡 접근 및 설계**
string 객체의 find함수를 사용하여 찾은 문자열의 인덱스를 반환하고 찾으면 갯수를 세주는 변수 a, b를 증가 시켜준다.

### **✏️ 알고리즘 풀이**
```c++
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
```
## **💭 오늘의 회고**
string 객체의 find 함수를 사용하여 인덱스 값을 반환하여 문제를 해결했다.