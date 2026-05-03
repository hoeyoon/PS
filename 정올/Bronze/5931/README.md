## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/5931?cursor=NiwwLDU=)

### 문제

정사각형의 한 변의 길이 n을 입력받은 후 다음과 같은 정사각형 형태로 출력하는 프로그램을 작성하시오.

![](https://s.jungol.co.kr/problem/77747/1RzRlc.eqmfqN6h-Cdd4Ya.webp)

### 입력
정사각형 한 변의 길이 
n을 입력받는다. (1≤n≤100)

### 출력
형식에 맞춰 출력한다. 숫자 사이는 공백으로 구분하여 출력한다.


#### 예제 #1
**입력**
```plaintext
3
```
**출력**
```plaintext
1 1 1
2 2 2
3 3 3
```

#### 예제 #2
**입력**
```plaintext
5
```
**출력**
```plaintext
1 1 1 1 1
2 2 2 2 2
3 3 3 3 3
4 4 4 4 4
5 5 5 5 5
```
## **💡 접근 및 설계**
각 줄에 i의 값을 n번 출력한다.

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << i + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
```
## **💭 오늘의 회고**
간단한 문제 풀이