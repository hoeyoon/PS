## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/1740?cursor=NiwzLDM=)

### 문제
자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최소값을 찾는 프로그램을 작성하시오.

예를 들어 M = 60, N = 100 60이상 100이하의 자연수 중 소수는 61,67,71,73,79,83,89,97 총 8개가 있으므로,    
이들 소수의 합은 620이고, 최소값은 61이 된다.

### 입력
입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.   
M과 N은 10,000이하의 자연수이며, M은 N보다 같거나 작다.

### 출력
M이상 N이하의 자연수 중 소수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최소값을 출력한다.  
단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 −1을 출력한다.

#### 예제
**입력**
```plaintext
60 
100
```
**출력**
```plaintext
620 
61
```
## **💡 접근 및 설계**
m부터 n까지 반복문을 돌리고 i가 소수라면 sum에 값을 i만큼 증가시키고 i가 min보다 작으면 min에 i값을 저장한다.

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
    int m, n;
    cin >> m >> n;
    int sum = 0;
    int min = 10001;
    for(int i = m; i <= n; i++){
        if(isPrime(i)){
            if(min > i){
                min = i;
            }
            sum += i;
        }
    }
    if(sum == 0 && min == 10001){
        cout << -1 << endl;
    }
    else{
        cout << sum << endl << min << endl;
    }
    return 0;
}
```
## **💭 오늘의 회고**
간단한 문제 풀이