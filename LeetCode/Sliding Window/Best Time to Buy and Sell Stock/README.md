## **💻 문제 설명**
[문제링크](https://neetcode.io/problems/buy-and-sell-crypto/question?list=neetcode150)

### 주식을 사고팔기 가장 좋은 시기 (Best Time to Buy and Sell Stock)
**난이도 : Easy, 알고리즘 종류: Array, DP**

$i$번째 날의 NeetCoin 가격인 `prices[i]`가 포함된 정수 배열 `prices`가 주어집니다.

당신은 NeetCoin을 구매할 **단 하루**를 선택할 수 있고, 해당 구매일 이후의 **미래의 다른 날**을 선택하여 판매할 수 있습니다.

당신이 얻을 수 있는 **최대 이익**을 반환하세요. 만약 어떠한 거래도 할 수 없다면(이익을 낼 수 없다면), 이익은 **0**이 됩니다.

---

#### 예시 1:
* **입력:** prices = [10, 1, 5, 6, 7, 1]
* **출력:** 6
* **설명:** index 1일 때(가격 1) 사고, index 4일 때(가격 7) 팝니다. 이익 = $7 - 1 = 6$.

#### 예시 2:
* **입력:** prices = [10, 8, 7, 5, 2]
* **출력:** 0
* **설명:** 이익을 낼 수 있는 거래가 없으므로 최대 이익은 0입니다.

---

#### 제약 사항:
* $1 \le prices.length \le 100$
* $0 \le prices[i] \le 100$


## **💡 접근 및 설계**

저번에 풀어본 Two Pointers 알고리즘을 사용해보기로 했다. 오른쪽 포인터에서 왼쪽 포인터를 뺀값이 변수 m보다 크면 m에 저장하고 포인터를 오른쪽으로 변경해준다.
왼쪽 포인터의 값이 더크면 왼쪽포인터를 오른쪽 포인터로 옮겨준다.

### **✏️ 알고리즘 풀이**
#### 나의풀이 (Two Pointer)
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, r = 1;
        int m = 0;
        while(r < prices.size()){
            if(prices[l] < prices[r]){
                m = max(m, prices[r] - prices[l]);
            }
            else{
                l = r;
            }
            r++;
        }
        return m;
    }
};
```
$$시간복잡도: O(n)$$
$$공간복잡도: O(1)$$

#### Brute Force 풀이
```c++
class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 0; i < prices.size(); i++) {
            int buy = prices[i];
            for (int j = i + 1; j < prices.size(); j++) {
                int sell = prices[j];
                res = max(res, sell - buy);
            }
        }
        return res;
    }
};
```
```plaintext
배열의 값을 전체 다 비교해본다.
그중에서 가장 값이 큰수를 리턴한다.
```
$$시간복잡도: O(n^2)$$
$$공간복잡도: O(1)$$

#### DP 풀이
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minBuy = prices[0];

        for (int& sell : prices) {
            maxP = max(maxP, sell - minBuy);
            minBuy = min(minBuy, sell);
        }
        return maxP;
    }
};
```
```plaintext
최대이익 변수 maxP를 0으로 초기화
최소가격의 주식을 저장하는 변수 minBuy
반복문을 돌려서 모든 prices를 확인한다.
maxP와 sell에서 minBuy를 뺀값 중 큰 값을 maxP에 저장
minBut와 sell중 작은 값을 minBuy에 저장
maxP 리턴
```
$$시간복잡도: O(n)$$
$$공간복잡도: O(1)$$

## **💭 오늘의 회고**
처음에 반복문을 두 번 사용하여 풀려고 했는데 저번에 사용한 Two Pointer 알고리즘이 생각났다. 두 값의 차가 가장 큰 값을 리턴하는 방식으로 풀었는데 맞았다. 배운 알고리즘을 활용해서 풀어보니 신기했다.