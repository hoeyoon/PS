## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/5946?cursor=NiwyLDQ=)

### 문제

삼각형의 높이 n을 입력받은 후 다음과 같은 삼각형 형태로 출력하는 프로그램을 작성하시오.

![](https://s.jungol.co.kr/board/1/0AhwHBI6wZ2Yfv9SBIKKwS.webp)

### 입력
삼각형의 크기 n (n의 범위는 50 이하의 홀수)을 입력받는다.

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
0 0 0 0 0
  1 1 1
    2
```

#### 예제 #2
**입력**
```plaintext
7
```
**출력**
```plaintext
0 0 0 0 0 0 0 0 0 0 0 0 0 
  1 1 1 1 1 1 1 1 1 1 1 
    2 2 2 2 2 2 2 2 2 
      3 3 3 3 3 3 3 
        4 4 4 4 4 
          5 5 5 
            6
```
## **💡 접근 및 설계**
공백을 2의 배수 만큼 출력 해준다. (n - i) * 2 - 1만큼 i를 출력해준다.

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if(n <= 50 && n % 2 == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i * 2; j++){
                cout << " ";
            }
            for(int j = 0; j < (n - i) * 2 - 1; j++){
                cout << i << " ";
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