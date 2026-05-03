## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/5945?cursor=NiwyLDM%3D)

### 문제
삼각형의 높이 n를 입력받은 후 다음과 같은 삼각형 형태로 출력하는 프로그램을 작성하시오.

< 처리조건 >
1. 숫자의 진행 순서는 처음에 왼쪽에서 오른쪽으로 진행 한다.
2. 다음줄은 방향을 바꾸어서 오른쪽에서 왼쪽으로 진행한다.
3. 1, 2를 n까지 반복한다.

![](https://s.jungol.co.kr/problem/1/0rfRVR_Hn7PeUHNOWl5StM.webp)

### 입력
삼각형의 크기 n(n의 범위는 1이상 50 이하의 홀수)을 입력받는다.


### 출력
삼각형의 높이는 n에 맞춰서 출력한다. 숫자사이는 공백으로 구분한다.  
입력된 데이터가 주어진 범위를 벗어나면 "INPUT ERROR!"을 출력한다.

#### 예제 #1
**입력**
```plaintext
3
```
**출력**
```plaintext
1 
3 2
4 5 6
```

#### 예제 #2
**입력**
```plaintext
5
```
**출력**
```plaintext
1
3 2
4 5 6
10 9 8 7
11 12 13 14 15
```
## **💡 접근 및 설계**
홀수 번째 출력은 c의 값이 후위증가하며 출력하고, 짝수 번째 출력은 c의 값이 전위감소하며 출력한다. 첫 번째 출력 이 후에 홀 수번째 출력이라면 c의 값을 감소시킨다.

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    if((1 <= n && n <= 50) && n % 2 == 1){
        int c = 0;
        for(int i = 1; i <= n; i++){
            c += i;
            if(i > 2 && i % 2 == 1){
                c--;
            }
            for(int j = 0; j < i; j++){
                if(i % 2 == 1){
                    cout << c++ << " ";
                }
                else{
                    cout << --c << " ";
                }
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