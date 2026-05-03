## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/1071?cursor=NiwxLDI=)

### 문제

주어진 정수들 중 입력 받은 수의 약수와 배수의 합을 각각 출력하라.

예를 들면,  
6개의 정수 2, 3, 5, 12, 18, 24 가 주어지고 12를 입력 받은 경우  
12의 약수는 2, 3, 12 이고  
12의 배수는 12, 24 이다.

### 입력
첫 줄에 정수의 개수 n (1≤n≤40)을 입력 받는다.  
둘째 줄에는 n개의 정수를 한 줄에 입력 받는다.  
셋째 줄에는 약수와 배수를 구할 정수 m (1≤m≤100)을 입력 받는다.

### 출력
첫 줄에는 정수 m의 약수의 합을 둘째 줄에는 정수 m의 배수의 합을 출력한다.

#### 예제
**입력**
```plaintext
6 
2 3 5 12 18 24 
12
```

**출력**
```plaintext
17 
36
```
## **💡 접근 및 설계**
m % k == 0 이면 k는 m의 약수이다.  
k % m == 0 이면 k는 m의 배수이다.

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

int main(){
    int n;
    int m;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cin >> m;
    int div = 0, mul = 0;
    for(int i = 0; i < n; i++){
        if(m % arr[i] == 0){
            div += arr[i];
        }
        if(arr[i] % m == 0){
            mul += arr[i];
        }
    }
    cout << div << endl << mul << endl;
    return 0;
}
```
## **💭 오늘의 회고**
간단한 문제 풀이