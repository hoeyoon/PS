## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/5934?cursor=NiwyLDE%3D)

### 문제


삼각형의 높이 n을 입력 받은 후 출력 예제과 같은 삼각형 형태로 출력하는 프로그램을 작성하시오. 

### 입력
100 이하의 홀수인 양의 정수 n이 주어진다.


### 출력
입력된 데이터가 주어진 범위를 벗어나면 "INPUT ERROR!"을 출력한다.  
\'\*\' 과 \'\*\' 사이에는 공백이 없다.


#### 예제 #1
**입력**
```plaintext
0
```

**출력**
```plaintext
INPUT ERROR!
```

#### 예제 #2
**입력**
```plaintext
3
```

**출력**
```plaintext
**
 *
 **
```

#### 예제 #3
**입력**
```plaintext
7
```
**출력**
```plaintext
****
 ***
  **
   *
   **
   ***
   ****
```

## **💡 접근 및 설계**
조건에 맞게 풀이

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n;
    if(n <= 100 && n % 2 == 1){
        for(int i = 0; i < n / 2 + 1; i++){
            for(int j = 0; j < i; j++){
                cout << " ";
                k = i;
            }
            for(int j = 0; j < (n / 2 - i + 1); j++){
                cout << "*";
            }
            cout << endl;
        }
        for(int i = 1; i < n / 2 + 1; i++){
            for(int j = 0; j < k; j++){
                cout << " ";
            }
            for(int j = 0; j < i + 1; j++){
                cout << "*";
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