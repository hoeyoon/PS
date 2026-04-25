## **💻 문제 설명**
[문제링크](https://neetcode.io/problems/two-integer-sum/question?list=neetcode150)

#### 두 수의 합 (Two Sum)
**난이도 : Easy, 알고리즘 종류: Array, Hash Table**
```
문제 설명:
정수 배열 nums와 정수 target이 주어졌을 때, nums[i] + nums[j] == target을 만족하는 두 인덱스 i와 j를 반환하세요. (단, i != j여야 합니다.)

모든 입력에는 조건을 만족하는 인덱스 쌍 i와 j가 정확히 하나만 존재한다고 가정해도 좋습니다.

결과를 반환할 때는 작은 인덱스를 먼저 표시하세요.

예제 1:

입력: nums = [3, 4, 5, 6], target = 7

출력: [0, 1]

설명: nums[0] + nums[1] == 7 이므로 [0, 1]을 반환합니다.

예제 2:

입력: nums = [4, 5, 6], target = 10

출력: [0, 2]

예제 3:

입력: nums = [5, 5], target = 10

출력: [0, 1]

제약 사항:

2 <= nums.length <= 1,000

-10,000,000 <= nums[i] <= 10,000,000

-10,000,000 <= target <= 10,000,000

오직 하나의 유효한 정답만 존재합니다.
```

## **💡 접근 및 설계**
반복문을 두 번 사용하여 두 값을 서로 더해 target이랑 같으면 answer벡터에 값 추가

### **✏️ 알고리즘 풀이**
#### 처음 풀이
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answer;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    answer.push_back(i);
                    answer.push_back(j);
                }
            }
        }
        return answer;
    }
};
```
$$시간복잡도: O(n^2)$$
$$공간복잡도: O(1)$$
#### 정렬 풀이
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> A;
        for (int i = 0; i < nums.size(); i++) {
            A.push_back({nums[i], i});
        }

        sort(A.begin(), A.end());

        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int cur = A[i].first + A[j].first;
            if (cur == target) {
                return {min(A[i].second, A[j].second),
                        max(A[i].second, A[j].second)};
            } else if (cur < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};
```
```plaintext
vector A를 생성하여 nums의 값과 인덱스 값 추가
A 정렬 후 정수 i = 0, j = nums.size() - 1로 초기화
두 값을 더한 값이 target과 같다면 
{두 인덱스를 비교하여 작은 값, 두 인덱스를 비교하여 큰 값} 리턴
```

$$시간복잡도: O(n log n)$$
$$공간복잡도: O(n)$$

#### 해쉬 맵 풀이(Two Pass)
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indices;  // val -> index

        for (int i = 0; i < nums.size(); i++) {
            indices[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (indices.count(diff) && indices[diff] != i) {
                return {i, indices[diff]};
            }
        }

        return {};
    }
};
```
```plaintext
해시맵을 생성하고 모든 배열 요소를 맵에 {값, 인덱스}로 저장
target - nums[i]의 값이 indices에 존재하는지 확인(자기 자신을 두 번 사용하는 거 방지)
존재하면 {i, 찾은 인덱스} 리턴
```
$$시간복잡도: O(n)$$
$$공간복잡도: O(n)$$

#### 해시 맵 풀이(One Pass)
```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> prevMap;

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];
            if (prevMap.find(diff) != prevMap.end()) {
                return {prevMap[diff], i};
            }
            prevMap.insert({nums[i], i});
        }
        return {};
    }
};
```
```plaintext
prevMap 생성
target - nums[i]가 prevMap에 존재하면 {prevMap[diff], i} 리턴
없다면 prevMap에 {nums[i], i} 리턴
```
$$시간복잡도: O(n)$$
$$공간복잡도: O(n)$$

## **💭 오늘의 회고**   
나는 반복문을 두 번 사용하여 문제를 해결하였는데 솔루션을 보니 해시 맵 사용하면 시간복잡도 O(n)으로 해결할수 있다는 것을 알게 되었다. 해시 맵에 대해서 좀 더 공부해보자.