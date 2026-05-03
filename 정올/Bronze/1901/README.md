## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/1901?cursor=NiwzLDI=)

### 문제

소수(prime number)란 2이상의 수로써 1과 자기 자신 외에는 약수를 갖지 않는 수를 의미한다.  
임의의 M값에 대하여 M에 가장 가까운 소수를 구하는 프로그램을 아래 조건에 따라 작성한다.

### 입력
첫 번째 줄에는 처리해야 할 수의 개수 N을 입력 받는다. (1≤N≤100)  
다음 줄에는 처리해야할 수 N개(M1 부터 MN까지)를 한 줄에 한 개씩 차례로 입력 받는다. (Mi는 1,000,000 이하의 양의 정수)  
데이터의 크기가 주어진 범위를 벗어나는 입력은 없다.


### 출력
임의의 값 Mi에 대해 차이가 가장 작은 소수를 구하여 출력한다.  
만약 차이가 같은 소수가 여러 개이면 작은 수부터 모두 출력한다.  
출력되는 값은 1이상 1,000,000 이하의 소수이어야 한다.


#### 예제
**입력**
```plaintext
2 
8 
15
```
**출력**
```plaintext
7 
13 17
```

## **💡 접근 및 설계**
m이 자기자신이 소수인지 판별한다. m - j, m + j의 값이 소수라면 출력하고 chk를 true로 저장한다.

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

bool isPrime(int n){
    if(n < 2){
        return false;
    }
    for(int i = 2; i <= n / i; i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int m;
        cin >> m;
        if(isPrime(m)){
            cout << m << endl;
            continue;
        }
        bool chk = false;
        for(int j = 1; !chk; j++){
            if(isPrime(m - j)){
                cout << m - j << " ";
                chk = true;
            }
            if(isPrime(m + j)){
                cout << m + j << " ";
                chk = true;
            }
        }
        cout << endl;
    }
    return 0;
}
```
## **💭 오늘의 회고**
처음에는 m보다 작은 소수 찾는 반복문, m보다 큰 소수 찾는 반복문을 설정하고 찾은 소수를 m과 차이를 구하여 출력했는데 여러가지 경우의 수가 더 나왔다.