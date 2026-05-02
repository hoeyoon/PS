## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/1146?cursor=Niw2LDA=)

### 문제

선택 정렬(selection sort)이란 내부정렬 알고리즘의 하나로 다음 순서대로 실행하여 정렬을 한다.

1. 주어진 수열 중에 최소값(같은 값이 여러 개 있는 경우 처음 값)을 찾는다.
2. 찾은 최소값을 맨 앞의 값과 자리를 바꾼다.
3. 맨 앞의 값을 뺀 나머지 수열을 같은 방법으로 전체 개수-1번 반복 실행한다.

n개의 주어진 수열을 위와 같은 방법으로 정렬한다. 

수열이 주어지면 선택정렬의 과정을 한 단계씩 출력한다.​ 

### 입력
첫줄에 수열의 길이 N(4≤N≤100)이 주어진다. 두 번째 줄에 
N
N개의 0이상 100이하의 정수가 주어진다.

### 출력
처음 상태를 제외하고 정렬과정의 각 단계별 결과를 "출력형식"과 같이 출력한다.


#### 예제
**입력**
```plaintext
5 
6 4 8 3 1
```
**출력**
```plaintext
1 4 8 3 6 
1 3 8 4 6 
1 3 4 8 6 
1 3 4 6 8
```

## **💡 접근 및 설계**
선택 정렬을 사용하고 단계별로 출력한다.

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

int main(){
    int n;
    int idx;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n - 1; i++){
        int min = 101;
        for(int j = i; j < n; j++){
            if(min > arr[j]){
                min = arr[j];
                idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[idx];
        arr[idx] = temp;
        for(int j = 0; j < n; j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```
## **💭 오늘의 회고**
정렬 알고리즘의 하나인 선택정렬 알고리즘을 배웠다.
선택정렬 알고리즘은 주어진 배열에서 최솟값을 찾고 맨 앞에 위치한 값과 교체한다.