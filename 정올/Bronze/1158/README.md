## **💻 문제 설명**
[문제링크](https://jungol.co.kr/problem/1158?cursor=Niw2LDE=)

### 문제

삽입정렬(Insertion sort)은 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여,  
자신의 위치를 찾아 삽입하는 정렬이다.

현재 i번째 원소를 정렬할 차례라면 i-1번째 까지는 정렬된 상태이다.  
i번째 부터 이후의 원소는 정렬되지 않은 상태이다.  
i번째 원소를 정렬된 상태에 포함시키는 작업을 마지막 원소까지 진행하여 정렬을 완성한다.

![](https://s.jungol.co.kr/board/63/04yWlK7A-Wj.zwEAm_1Xz4/%ED%8C%8C%EC%9D%BC)

* $$시간복잡도 : 최악의 경우 O(N^2), 최선의 경우 O(N), 평균의 경우 O(N^2).$$
* $$공간복잡도 O(N).$$
* in place 정렬 : 추가 배열이 필요하지 않다.
* stable sort(안정 정렬) : 같은 값인 경우 초기 순서를 보장한다.
* 선택정렬, 버블정렬보다 빠르다. cf) https://ko.wikipedia.org/wiki/%EC%82%BD%EC%9E%85_%EC%A0%95%EB%A0%AC

* 배열의 길이가 작은 경우( gcc: 16이하, vc: 32이하) $$O(Nlog(N))$$ 정렬보다 더 효율적일 수 있다.
cf) https://jungol.co.kr/problem/3520



수열이 {5 4 3 7 6}이 있을 경우의 삽입정렬 과정은 다음과 같다.  
초기 처음 값 5 앞에 아무것도 없으므로 5는 이미 정렬된 상태가 되므로, 이후 4부터 정렬 과정을 살펴보자.

![](https://s.jungol.co.kr/board/63/2VqVzVjZFjI.mEkqNgqSeI/%ED%8C%8C%EC%9D%BC)

※ 3단계의 경우 7은 앞의 "3 4 5"보다 크므로 제자리에 삽입된다.

n개의 수열이 주어지면 위와 같은 방법으로 정렬하는 과정 각 단계를 출력하는 프로그램을 작성하시오.


```python
//  A[0] ~ A[N-1]  에 데이터가 저장된 상태. 

for ( i = 1 ~ N-1 ):
    tg = A[i] 
    for ( j= i-1 ~ 0 ):
        if (A[j] > tg ) A[j+1] = A[j]
        else break
    A[j+1] = tg
    // A[0] ~ A[N-1] 를 출력 
```

### 입력
첫 줄에 수열의 길이 N(4 ≤ N ≤ 100)이 주어진다.  
두 번째 줄에 N개의 0이상 100이하의 정수가 주어진다.

## 출력
처음 상태를 제외하고 정렬 과정의 각 단계별 결과를 "출력 예"와 같이 출력한다.

#### 예제
**입력**
```plaintext
5 
5 4 3 7 6
```
**출력**
```plaintext
4 5 3 7 6 
3 4 5 7 6 
3 4 5 7 6 
3 4 5 6 7
```
## **💡 접근 및 설계**
삽입정렬을 사용하고 단계별로 출력한다.

### **✏️ 알고리즘 풀이**
```c++
#include <iostream>
using namespace std;

int main(){
    int n, key;
    int i, j;
    cin >> n;

    int arr[n];
    for(i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(i = 1; i < n; i++){
        key = arr[i];
        for(j = i - 1; j >= 0 && arr[j] > key; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
        for(j = 0; j < n; j++){
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```
## **💭 오늘의 회고**
정렬 알고리즘 중 하나인 삽입정렬을 알게 되었다.    
삽입정렬은 자료 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여 자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘이다.