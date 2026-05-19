## **💻 문제 설명**
[문제링크](https://neetcode.io/problems/top-k-elements-in-list/question)

#### Top K Frequent Elements

정수 배열 nums와 정수 k가 주어졌을 때, 배열 내에서 가장 빈도가 높은 k개의 요소를 반환하라.
테스트 케이스는 답이 항상 유일하도록 생성된다.
출력 형식의 순서는 상관없다.

예시 1:
입력: nums = [1,2,2,3,3,3], k = 2
출력: [2,3]

예시 2:
입력: nums = [7,7], k = 1
출력: [7]

제약 조건:
1 <= nums.length <= 10^4
-1000 <= nums[i] <= 1000
1 <= k <= nums에 있는 서로 다른 요소의 개수

## **💡 접근 및 설계**
해시테이블을 사용하고 배열에 key의 값을 세어준다.
정수 2개를 저장하는 벡터를 만들고 second와 first의 값을 바꿔서 arr에 저장한다. 그 후 arr를 내림차순으로 정렬하고 k번 second의 값을 출력한다.


### **✏️ 알고리즘 풀이**
#### 나의 풀이 (정렬)
```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(auto &it : nums){
            m[it]++;
        }
        vector<pair<int, int>> arr;
        for(auto &it : m){
            arr.push_back({it.second, it.first});
        }
        sort(arr.rbegin(), arr.rend());
        
        vector<int> result;
        for(int i = 0; i < k; i++){
            result.push_back(arr[i].second);
        }
        return result;
    }
};
```
$$시간복잡도 : O(n log n)$$
$$공간복잡도 : O(n)$$

#### 2. 최소 힙 (Min-Heap)

**직관**  
각 숫자가 얼마나 자주 나타나는지 세어본 후, 가장 빈도가 높은 k개의 요소만 효율적으로 추적하고자 합니다.  
최소 힙은 항상 가장 작은 요소를 맨 위에 유지하기 때문에 이 작업에 완벽하게 들어맞습니다.  
힙에 (빈도, 값) 쌍을 추가하고 힙의 크기가 k를 초과할 때마다 가장 작은 요소를 제거함으로써, 힙이 항상 가장 빈도가 높은 상위 k개의 요소를 포함하도록 보장합니다.  
결국 힙에는 정확히 가장 높은 빈도를 가진 k개의 값만 남게 됩니다.

**알고리즘**

* 각 숫자가 몇 번 나타나는지 세어주는 빈도 맵을 구축합니다.
* 비어 있는 최소 힙을 생성합니다.
* 빈도 맵의 각 숫자에 대해: (빈도, 숫자)를 힙에 추가합니다(Push).
* 만약 힙의 크기가 k보다 커지면, 한 번 꺼내어(Pop) 가장 작은 빈도를 제거합니다.
* 모든 숫자를 처리한 후, 힙에는 가장 빈도가 높은 k개의 요소가 포함됩니다.
* 힙에서 모든 요소를 꺼내어(Pop) 결과 리스트에 해당 숫자들을 수집합니다.
* 결과를 반환합니다.
```c++
class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
        for (auto& entry : count) {
            heap.push({entry.second, entry.first});
            if (heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(heap.top().second);
            heap.pop();
        }
        return res;
    }
};
```
$$시간복잡도 : O(n log k)$$
$$공간복잡도 : O(n + k)$$

#### 3. 버킷 정렬 (Bucket Sort)

**직관**  
배열의 각 숫자는 특정 횟수만큼 나타나며, 발생할 수 있는 최대 빈도는 배열의 길이입니다.    
이 아이디어를 활용하여 인덱스가 빈도를 나타내는 리스트를 만들고, 각 인덱스에 정확히 그 횟수만큼 나타나는 모든 숫자를 저장할 수 있습니다.  
예를 들어:   
* 1번 나타나는 모든 숫자는 freq[1] 그룹에 들어갑니다.
* 2번 나타나는 모든 숫자는 freq[2] 그룹에 들어갑니다.
* 이런 식으로 계속됩니다.  

이러한 그룹들을 만든 후, 발생할 수 있는 가장 높은 빈도부터 가장 낮은 빈도까지 내려가며 k개가 될 때까지 이 그룹들에서 숫자들을 수집합니다.
이렇게 하면 모든 요소를 빈도순으로 정렬하지 않고도 가장 자주 등장하는 숫자로 바로 건너뛸 수 있습니다.

**알고리즘**

* 각 숫자가 몇 번 나타나는지 세어주는 빈도 맵을 구축합니다.
* freq[i]에 정확히 i번 나타나는 모든 숫자를 저장할 그룹 리스트 freq를 생성합니다.
* 빈도 맵에 있는 각 숫자와 그 빈도에 대해, 해당 숫자를 freq[빈도]에 추가합니다.
* 비어 있는 결과 리스트를 초기화합니다.
* 가장 큰 빈도부터 1까지 역순으로 반복문을 돌립니다: freq[i]에 있는 각 숫자를 결과 리스트에 추가합니다.
* 결과 리스트에 k개의 숫자가 채워지면, 이를 반환합니다.
```c++
class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int n : nums) {
            count[n] = 1 + count[n];
        }
        for (const auto& entry : count) {
            freq[entry.second].push_back(entry.first);
        }

        vector<int> res;
        for (int i = freq.size() - 1; i > 0; --i) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;
    }
};
```
$$시간복잡도 : O(n)$$
$$공간복잡도 : O(n)$$
## **💭 오늘의 회고**
최소 힙을 사용하여 문제를 해결 할 수 있다. 힙의 사이즈가 k보다 크다면 힙의 요소를 삭제한다. 키의 값을 삭제하면서 결과 벡터에 넣는다.
버킷 정렬을 사용해서도 해결 할 수 있다. 2차원 배열에서 key에 맞는 인덱스에 value를 저장한다. 뒤에서 부터 값을 찾아 res 벡터에 저장한다. res의 크기가 k와 같다면 res를 리턴한다.
STL를 좀 더 공부해야겠다.