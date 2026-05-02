## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/1309?cursor=Niw3LDA=)

### 문제

1부터 어떤 양의 정수 n까지의 정수를 모두 곱한 것을 말하며 n!로 나타낸다.  
0! = 1  
1! = 1  
2! = 2  
n! = n * (n-1)!  
：  
와 같이 정의된다.

예로 4! = 4×3×2×1 = 24 이다.

n! 이 주어졌을 때 결과를 출력하는 프로그램을 작성하라.

 

\* 결과가 int범위를 넘는 경우 자료형 long long 입력/출력 서식문자 %lld 를 사용한다.


### 입력
입력은 한 줄로 이뤄지며 팩토리얼의 숫자 n(1≤n≤15)이 입력된다.


### 출력
n!에 대한 계산 결과를 "출력예"처럼 과정을 출력하고 마지막에 결과를 출력한다.


#### 예제
**입력**
```plaintext
4
```
**출력**
```plaintext
4! = 4 * 3! 
3! = 3 * 2! 
2! = 2 * 1! 
1! = 1 
24
```
## **💡 접근 및 설계**
fac이라는 함수를 만들고 n * fac(n - 1)을 리턴하는 재귀함수를 만든다. 주어진 조건에 맞게 출력한다.

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

long long fac(int n){
    if(n == 1){
        cout << "1! = 1" << endl;
        return 1;
    }
    else{
        cout << n << "! = " << n << " * " << n - 1 << "!" << endl;
        return  n * fac(n - 1);
    }
}

int main(){
    int n;
    long long answer = 0;

    cin >> n;
    answer = fac(n);
    cout << answer << endl;
    return 0;
}
```
## **💭 오늘의 회고**
팩토리얼을 이용하는 기초적인 재귀함수 문제이다.