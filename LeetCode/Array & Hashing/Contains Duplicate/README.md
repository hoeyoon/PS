## **💻 문제 설명**

[문제링크](https://neetcode.io/problems/duplicate-integer/question?list=neetcode150)

#### 중복 요소 포함 여부 (Contains Duplicate)
```
문제 설명:
정수 배열 nums가 주어졌을 때, 배열 안의 어떤 특정한 값이 두 번 이상 나타나면 true를 반환하고, 모든 요소가 서로 다르면 false를 반환하세요.

예제 1
입력: nums = [1, 2, 3, 3]

출력: true

이유: 숫자 3이 두 번 나타났으므로 중복이 존재합니다.

예제 2
입력: nums = [1, 2, 3, 4]

출력: false

이유: 모든 숫자가 단 한 번씩만 나타나며, 중복된 숫자가 없습니다.
```

## **💡 접근 및 설계**

#### 처음 풀이
반복문을 2번 사용하여 값을 찾아 두 번 이상 나타나면 true리턴 아니면 false리턴

#### 나중 풀이
배열을 먼저 오름차순 정렬한다음 앞의 값과 뒤의 값을 비교하여 두 값이 같다면 true 리턴 false 리턴

### **✏️ 알고리즘 풀이**

#### 처음 풀이
```c++
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < len; i++){
            for(int j = i + 1; j < len; j++){
                if(nums[i] == nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};
```
**시간복잡도:** $$O(n^2)$$

#### 나중풀이
```c++
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 1; i < len; i++){
            if(nums[i] == nums[i - 1]){
                return true;
            }
        }
        return false;
    }
};
```
**시간복잡도:** $$O(n)$$

## **💭 오늘의 회고**

반복문을 두번 사용하여 풀었는데 시간복잡도가 O(n^2)이 나와 큰 값이 들어오면 Time Limit 에러가 나왔다 그래서 오름차순 정렬하고 앞의 값과 뒤의 값을 비교하여 풀었다. 시간복잡도가 O(n)이 나왔고 문제를 해결하였다. 문제를 풀 때 시간복잡도를 꼭 생각하고 풀어보자