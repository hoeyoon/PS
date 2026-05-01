## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/1329?cursor=NiwyLDI=)

### 문제
삼각형의 높이 N을 입력받아 아래와 같은 모양을 출력하는 프로그램을 작성하시오.  
![](https://u.jungol.co.kr/problem/1329/ed60a0d1-c51b-48d6-9131-32b52b931360.png)


### 입력
삼각형의 높이 N(N의 범위는 100 이하의 양의 홀수)을 입력받는다.


### 출력
N의 높이에 맞추어 주어진 형태의 모양을 출력한다.  
입력된 데이터가 주어진 범위를 벗어나면 "INPUT ERROR!"를 출력한다.


#### 예제 #1
**입력**
```plaintext
7
```
**출력**
```plaintext
* 
 *** 
  ***** 
   ******* 
  ***** 
 *** 
*
```

#### 예제 #2
**입력**
```plaintext
5
```
**출력**
```plaintext
*
 ***
  *****
 ***
*
```
## **💡 접근 및 설계**
조건에 맞게 출력

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n;
    if((1 <= n && n <= 100) && n % 2 == 1){
        for(int i = 0; i < n / 2 + 1; i++){
            for(int j = 0; j < i; j++){
                cout << " ";
                k = i;
            }
            for(int j = 0; j < i * 2 + 1; j++){
                cout << "*";
            }
            cout << endl;
        }
        for(int i = 1; i < n / 2 + 1; i++){
            for(int j = 0; j < k - 1; j++){
                cout << " ";
            }
            for(int j = 0; j < (n / 2 - i) * 2 + 1; j++){
                cout << "*";
            }
            k--;
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
간단한 문제풀이