## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/1009?cursor=NiwzLDA=)

### 문제

양의 정수를 입력받아 역으로 보여주고 각 자리 숫자의 합을 구하는 프로그램을 작성하라.

## 입력
21억 이하의 양의 정수를 입력받는다. 잘못된 데이터는 입력되지 않는다.   
하나의 결과가 나온 후에도 계속 새로운 입력을 받다가 0이 입력되면 프로그램을 종료한다.  
최대 10개의 양의 정수가 입력될 수 있다.

### 출력
입력받은 수의 역과 각 자리 숫자의 합을 공백으로 구분하여 출력한다.   
유효하지않은 "0"은 출력하지 않는다.   
입력받은 수의 역도 21억 이하의 정수이다.

#### 예제 #1
**입력**
```plaintext
453 
123456 
0
```
**출력**
```plaintext
354 12 
654321 21
```

#### 예제 #2
**입력**
```plaintext
10203040
3004000
54321
0
```
**출력**
```plaintext
4030201 10
4003 7
12345 15
```

## **💡 접근 및 설계**
각 자릿 수를 구해서 뒤에서 부터 출력, n의 나머지가 0이 아니라면 k = true k가 true일 때 만 출력, answer에 자릿 수를 더하고 answer 출력

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

int main(){
    unsigned int n;
    for(int i = 0; i < 10; i++){
        bool k = false;
        cin >> n;
        if(n == 0){
            break;
        }
        int answer = 0;
        while(n > 0){
            if(n % 10 != 0){
                k = true;
            }
            if(k == true){
                cout << n % 10;
            }
            answer += n % 10;
            n /= 10;
        }
        cout << " " << answer << endl;
    }
    return 0;
}
```
## **💭 오늘의 회고**
간단한 문제 풀이