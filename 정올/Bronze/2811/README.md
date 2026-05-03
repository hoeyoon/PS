## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/2811?cursor=NiwzLDE%3D)

### 문제
소수(prime number)란 1보다 큰 자연수 중 1과 자기 자신 두 개만을 약수로 갖는 수를 말한다.   
합성수(composite number)란 1보다 큰 자연수 중 소수가 아닌 수를 말하며 3개 이상의 약수를 갖는다.   
1은 소수도 합성수도 아니다.   
5개의 자연수를 입력받아 소수인지 합성수인지를 판단하는 프로그램을 작성하시오.

### 입력
10억 이하의 자연수 5개가 공백으로 구분되어 주어진다.

### 출력
입력된 순서대로 한 줄에 한 개씩 소수이면 "prime number",    
합성수이면 "composite number",   
소수도 합성수도 아니면 "number one"이라고 출력한다.

#### 예제
**입력**
```plaintext
3 10 1 55 127
```

**출력**
```plaintext
prime number
composite number
number one
composite number
prime number
```

## **💡 접근 및 설계**
n을 입력받고 n == 1이면 number one출력 소수이면 소수 판별 함수를 통해 prime number을 출력한다. 소수 판변 함수는 반복문을 2부터 루트 n까지 반복하고 나누어 떨어지는 수가 있다면 false를 리턴하고 없다면 true를 리턴한다.

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n){
    if(n < 2){
        return false;
    }
    for(long long i = 2; i <= sqrt(n); i++){
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    long long n;
    for(int i = 0; i < 5; i++){
        cin >> n;
        if(n == 1){
            cout << "number one" << endl;
        }
        else if(isPrime(n)){
            cout << "prime number" << endl;
        }
        else{
            cout << "composite number" << endl;
        }
    }
    return 0;
}
```
## **💭 오늘의 회고**
처음에는 카운트를 세는 방법으로 풀었는데 시간초과가 나왔다. 그래서 판별하는 함수를 만들고 반복문을 루트 n까지만 반복하여 시간을 단축하였다.