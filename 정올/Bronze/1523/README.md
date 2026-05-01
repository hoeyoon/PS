## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/1523?cursor=NiwyLDA=)

### 문제
삼각형의 높이 n과 종류 m을 입력 받은 후 다음과 같은 삼각형 형태로 출력하는 프로그램을 작성하시오.


### 입력
삼각형의 크기 n(n의 범위는 100 이하의 자연수)과 종류 m(m은 1부터 3사이의 자연수)을 입력받는다.

### 출력
위에서 언급한 3가지 종류를 입력에서 들어온 높이 n과 종류 m에 맞춰서 출력한다.  
입력된 데이터가 주어진 범위를 벗어나면 "INPUT ERROR!"을 출력한다.


#### 예제 #1
**입력**
```plaintext
3 2
```

**출력**
```plaintext
*** 
** 
*
```

#### 예제 #2
**입력**
```plaintext
4 3
```

**출력**
```plaintext
   * 
  *** 
 ***** 
*******
```

#### 예제 #3
**입력**
```plaintext
200 3
```
**출력**
```plaintext
INPUT ERROR!
```

#### 예제 #4
**입력**
```plaintext
3 1
```

**출력**
```plaintext
*
**
***
```

## **💡 접근 및 설계**
조건에 맞게 출력


### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

void print_1(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void print_2(int n){
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            cout << "*";
        }
        cout << endl;
    }
}

void print_3(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            cout << " ";
        }
        for(int j = 0; j < i * 2 + 1; j++){
            cout << "*";
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    if(n <= 100 && (1 <= m && m <= 3)){
        switch(m){
            case 1:
                print_1(n);
                break;
            case 2:
                print_2(n);
                break;
            case 3:
                print_3(n);
                break;
        }
    }
    else{
        cout << "INPUT ERROR!" << endl;
    }
    return 0;
}
```


## **💭 오늘의 회고**
간단한 반복문 문제