## **💻 문제 설명**
[문제링크](https://neetcode.io/problems/anagram-groups/question)

**그룹 아나그램 (Group Anagrams)**

**문제 설명**  
문자열 배열 `strs`가 주어지면, 모든 아나그램을 하위 리스트로 함께 그룹화하세요. 출력 순서는 상관없습니다.

아나그램이란 다른 문자열과 정확히 동일한 문자들을 포함하고 있지만, 문자들의 순서는 다를 수 있는 문자열을 의미합니다.

**예시 1:**

* **입력:** `strs = ["act","pots","tops","cat","stop","hat"]`
* **출력:** `[["hat"],["act", "cat"],["stop", "pots", "tops"]]`

**예시 2:**

* **입력:** `strs = ["x"]`
* **출력:** `[["x"]]`

**예시 3:**

* **입력:** `strs = [""]`
* **출력:** `[[""]]`

**제약 조건:**

* `1 <= strs.length <= 1000`
* `0 <= strs[i].length <= 100`
* `strs[i]`는 영문 소문자로만 구성되어 있습니다.

## **💡 접근 및 설계**
unordered_map을 사용하여 각 문자열을 정렬한 값을 키로 설정하고, 각 key에 원본 문자열을 저장한다.
result string 벡터에 r의 밸류값을 넣는다.

### **✏️ 알고리즘 풀이**
#### 나의 풀이(정렬)
```c++
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> r;
        for(auto &s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            r[temp].push_back(s);
        }
        vector<vector<string>> result;
        for(auto &it : r){
            result.push_back(it.second);
        }
        return result;
    }
};
```
$$시간복잡도:O(m * nlogn)$$
$$공간복잡도:O(m * n)$$

#### 1. 정렬 (Sorting)
**직관**  
아나그램은 그 문자들을 정렬했을 때 서로 동일해집니다.
예를 들어, "eat", "tea", "ate"는 정렬한 후에 모두 "aet"가 됩니다.   
각 문자열의 정렬된 버전을 키(key)로 사용함으로써, 우리는 모든 아나그램을 함께 그룹화할 수 있습니다.   
동일한 정렬된 형태를 공유하는 문자열들은 반드시 아나그램이어야 하므로, 이들을 같은 그룹에 배치하는 것은 자연스러우면서도 효율적입니다.   

**알고리즘**
1. 각 키가 문자열의 정렬된 버전이고, 값이 해당 아나그램 그룹에 속하는 문자열들의 리스트인 해시 맵을 생성합니다.
2. 입력 리스트의 각 문자열을 순회합니다: 
    * 문자열의 문자들을 정렬하여 키를 생성합니다.
    * 이 키에 해당하는 리스트에 원본 문자열을 추가합니다.
3. 모든 문자열을 처리한 후, 그룹화된 아나그램을 나타내는 해시 맵의 모든 값들을 반환합니다.
```c++
class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            string sortedS = s;
            sort(sortedS.begin(), sortedS.end());
            res[sortedS].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};
```
$$시간복잡도:O(m * nlogn)$$
$$공간복잡도:O(m * n)$$

#### 2. 해시 테이블 (Hash Table)
**직관**   
각 문자열을 정렬하는 대신, 우리는 모든 문자열을 문자들의 출현 빈도로 나타낼 수 있습니다.   
이 문제는 영문 소문자만 사용하므로, 길이가 26인 고정된 크기의 배열로 각 문자가 몇 번 나타나는지 포착할 수 있습니다.   
두 문자열은 오직 빈도 배열이 동일할 때만 아나그램이 됩니다.   
이 빈도 배열을 딕셔너리의 키로 사용할 수 있도록 튜플로 변환하여 사용함으로써, 동일한 문자 개수를 공유하는 모든 문자열을 그룹화할 수 있습니다.   
**알고리즘**   
1. 각 키가 문자 빈도를 나타내는 길이 26짜리 튜플이고, 각 값이 해당 아나그램 그룹에 속하는 문자열들의 리스트인 해시 맵을 생성합니다.
2. 입력의 각 문자열에 대해: 
    * 모든 값이 0으로 채워진 크기 26의 count 배열을 초기화합니다.
    * 문자열의 각 문자 c에 대해, 해당하는 인덱스의 카운트를 1 증가시킵니다.
    * count 배열을 튜플로 변환하여 키로 사용합니다.
    * 이 키와 연결된 리스트에 문자열을 추가합니다.
3. 모든 문자열을 처리한 후, 해시 맵에 저장된 모든 리스트를 반환합니다.
```c++
class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> res;
        for (const auto& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }
            string key = to_string(count[0]);
            for (int i = 1; i < 26; ++i) {
                key += ',' + to_string(count[i]);
            }
            res[key].push_back(s);
        }
        vector<vector<string>> result;
        for (const auto& pair : res) {
            result.push_back(pair.second);
        }
        return result;
    }
};
```
$$시간복잡도:O(m * n)$$
$$공간복잡도:O(m * n) or O(m)$$

## **💭 오늘의 회고**
정렬되지 않는 map을 사용하여 키 값에 따라 문자를 구분할 수 있다.
STL에 대해 좀 더 공부를 하자