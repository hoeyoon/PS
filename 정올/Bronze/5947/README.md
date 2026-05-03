## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/5947?cursor=NiwyLDU=)

### 문제

삼각형의 높이 n을 입력받은 후 다음과 같은 삼각형 형태로 출력하는 프로그램을 작성하시오.

![](https://s.jungol.co.kr/problem/1/0n_MpNXfTy9KECSz0qPPtn.webp)

### 입력
삼각형의 크기 n(n의 범위는 50 이하의 홀수)을 입력받는다.

### 출력
삼각형의 높이를 n에 맞춰서 출력한다. 숫자사이는 공백으로 구분한다.  
입력된 데이터가 주어진 범위를 벗어나면 "INPUT ERROR!"을 출력한다.


#### 예제 #1
**입력**
```plaintext
3
```
**출력**
```plaintext
1 
1 2 
1
```

#### 예제 #2
**입력**
```plaintext
7
```
**출력**
```plaintext
1
1 2
1 2 3
1 2 3 4
1 2 3
1 2
1
```
## **💡 접근 및 설계**
n / 2 + 1 번 반복문을 사용하고 i + 1번 j + 1을 출력하여 윗 삼각형을 만든다.   
n / 2 + 1 번 반복문을 사용하고 n / 2 + 1 - i번 j + 1을 출력하여 아래 삼각형을 만든다.

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n <= 50 && n % 2 == 1){
        for(int i = 0; i < n / 2 + 1; i++){
            for(int j = 0; j < i + 1; j++){
                cout << j + 1 << " ";
            }
            cout << endl;
        }
        for(int i = 1; i < n / 2 + 1; i++){
            for(int j = 0; j < (n / 2 + 1) - i; j++){
                cout << j + 1 << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "INPUT ERROR!" << endl;
    }
    return 0;
}
```
## **💭 오늘의 회고**
간단한 문제 풀이