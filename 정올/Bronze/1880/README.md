## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/1880?cursor=Niw0LDM=)

### 문제

최근 농부 창호에게서 메시지를 암호화(encryption)에 대해서 배운 소들은 너무나 신이 나있다.   
그들은 다른 농장의 소들과 미팅을 할 때 은밀한 메시지를 사용할 경우 이 방법을 사용할 수 있을 것이라고 생각했다.   
소들이 사용하는 암호화 방법은 복잡한 DES 혹은 BlowFish 와 같은 좋은 방법이 아니고 단순히 치환 하는 암호화 기법이다.  
소들의 경우 복호화(암호를 해독함)하는 시간이 오래 걸리기 때문에,   
소들과 대화를 할 수 있는 당신에게 복호화 키와 암호 문자를 입력으로 받아 원문을 구하는 프로그램을 구현 해주기를 요청했다.   
복호화 키는 26개의 소문자로 주어지며, a,b,c,d... 를 순서대로 복호화 키 문자로 대치한다는 것을 뜻한다.

예를 들어, 복호화 키가 "eydbkmiqugjxlvtzpnwohracsf" 와 같이 주어진다고 하자,   
그러면 이는 다음과 같다 - a 문자는 e, b 문자는 y, ..., z 문자는 f로 바꿔 준다.  
암호화 된 문자는 대소문자 혹은 공백이 올 수 있고 대문자는 대문자로 소문자는 소문자로 치환 규칙에 맞게 출력하고, 공백문자는 그대로 출력한다.

### 입력
첫 줄에는 복호화 키가 26개의 소문자로 주어지고, 다음 줄에는 암호화 된 문자가 최대 80 문자로 입력된다.

### 출력
암호화 된 문장을 복호화 시켜 원문을 출력한다.

#### 예제
**입력**
```plaintext
eydbkmiqugjxlvtzpnwohracsf 
Kifq oua zarxa suar bti yaagrj fa xtfgrj
```
**출력**
```plaintext
Jump the fence when you seeing me coming
```
## **💡 접근 및 설계**
복호화 키와 문자열을 입력받고 소문자면 encry[str[i] - 'a']의 값을 출력한다. 대문자면 소문자로 변환해서 글자를 구하고 다시 대문자로 출력한다.
알파벳 외 문자들은 출력한다.

### **✏️ 알고리즘 풀이**
```c++
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
```
## **💭 오늘의 회고**
간단한 문제 풀이