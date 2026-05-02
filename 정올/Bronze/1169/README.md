## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/1169?cursor=Niw3LDE=)

### 문제

주사위를 던진 횟수 N과 출력형식 type을 입력 받아서 type의 값에 따라 각각 아래와 같이 출력하는 프로그램을 작성하시오.

type = 1 : 주사위를 N번 던져서 나올 수 있는 모든 경우  
type = 2 : 주사위를 N번 던져서 중복이 되는 경우를 제외하고 나올 수 있는 모든 경우  
type = 3 : 주사위를 N번 던져서 모두 다른 수가 나올 수 있는 모든 경우

 

\* 중복의 예

1 1 2 와 중복 : 1 2 1, 2 1 1  
1 2 3 과 중복 : 1 3 2, 2 1 3, 2 3 1, 3 1 2​, 3 2 1


### 입력
첫 줄에 주사위를 던진 횟수 N(2≤N≤5)과 출력모양 type(1≤type≤3)이 들어온다.


### 출력
주사위를 던진 횟수 N에 대한 출력모양을 출력한다. 작은 숫자부터 출력한다.


#### 예제 #1
**입력**
```plaintext
3 1
```
**출력**
```plaintext
1 1 1
1 1 2
1 1 3
1 1 4
1 1 5
1 1 6
1 2 1
 ㆍ
 ㆍ  <- 너무 길어 생략
 ㆍ
6 6 3 
6 6 4 
6 6 5 
6 6 6
```

#### 예제 #2
**입력**
```plaintext
3 2
```
**출력**
```plaintext
1 1 1 
1 1 2 
1 1 3 
1 1 4 
1 1 5 
1 1 6 
1 2 2
 ㆍ
 ㆍ  <- 너무 길어 생략
 ㆍ
4 6 6 
5 5 5 
5 5 6 
5 6 6 
6 6 6
```

#### 예제 #3
**입력**
```plaintext
3 3
```
**출력**
```plaintext
1 2 3
1 2 4
1 2 5
1 2 6
1 3 2
1 3 4
 ㆍ
 ㆍ  <- 너무 길어 생략
 ㆍ
6 5 1 
6 5 2 
6 5 3 
6 5 4
```
## **💡 접근 및 설계**
첫번째 type인 경우 재귀의 깊이가 n에 도달할 때까지 1부터 6까지 반복문을 돌린다. dice배열에 i값을 저장하고 첫번째 type함수를 호출한다.   
두번째 type인 경우 매개변수에 start 변수를 추가해주고 반복문의 시작을 start로 해준다. 두번째 type함수를 호출하는데 매개변수로 start의 값을 준다.  
세번째 type인 경우 chk배열을 만들고 chk가 true이면 continue한다. chk를 true로 바꾸고 dice배열에 i를 저장한다. 세번째 type함수를 호출하고 재귀가 끝나고 돌아오면 chk를 false로 바꿔준다.


### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

int n;
int dice[10];
bool chk[10];

void print(){
    for(int i = 0; i < n; i++){
        cout << dice[i] << " ";
    }
    cout << endl;
}

void type_1(int cnt){
    if(cnt == n){
        print();
        return;
    }
    for(int i = 1; i <= 6; i++){
        dice[cnt] = i;
        type_1(cnt + 1);
    }
}

void type_2(int cnt, int start){
    if(cnt == n){
        print();
        return;
    }
    for(int i = start; i <= 6; i++){
        dice[cnt] = i;
        type_2(cnt + 1, i);
    }
}
void type_3(int cnt){
    if(cnt == n){
        print();
        return;
    }
    for(int i = 1; i <= 6; i++){
        if(chk[i]){
            continue;
        }
        chk[i] = true;
        dice[cnt] = i;
        type_3(cnt + 1);
        chk[i] = false;
    }
}

int main(){
    int type;
    cin >> n >> type;
    switch(type){
        case 1:
            type_1(0);
            break;
        case 2:
            type_2(0, 1);
            break;
        case 3:
            type_3(0);
            break;
    }
    return 0;
}
```
## **💭 오늘의 회고**
재귀함수를 이용해 주사위의 경우의 수를 출력한다.
재귀함수를 좀 더 연습해봐야겠다.