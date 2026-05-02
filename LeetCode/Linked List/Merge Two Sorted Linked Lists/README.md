## **💻 문제 설명**
[문제링크](https://neetcode.io/problems/merge-two-sorted-linked-lists/question)

### 두 정렬된 연결 리스트 병합하기 (Merge Two Sorted Linked Lists)

**난이도: Easy, 알고리즘 종류: Linked List, Recursion**

두 개의 정렬된 연결 리스트 `list1`과 `list2`의 헤드(head)가 주어집니다.

이 두 리스트를 하나의 **정렬된** 연결 리스트로 병합하고, 새롭게 정렬된 연결 리스트의 헤드를 반환하세요.
새 리스트는 `list1`과 `list2`의 노드들을 이어 붙여서 만들어야 합니다.

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/51adfea9-493a-4abb-ece7-fbb359d1c800/public)
---

### 예시 1:
**입력:** list1 = [1,2,4], list2 = [1,3,5]
**출력:** [1,1,2,3,4,5]

### 예시 2:
**입력:** list1 = [], list2 = [1, 2]
**출력:** []

### 예시 3:
**입력:** list1 = [], list2 = []
**출력:** []

---

### 제약 사항:
*   각 연결 리스트의 노드 개수는 `0`개에서 `50`개 사이입니다.
* `-100 <= Node.val <= 100`
* `list1`과 `list2`는 모두 비내림차순(non-decreasing)으로 정렬되어 있습니다.


## **💡 접근 및 설계**
temp 노드를 만들고 두 리스트의 노드 중 작은 값을 temp에 이어 붙인다. 마지막 노드를 연결한다.

### **✏️ 알고리즘 풀이**
#### 나의 풀이
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode temp(0);
        ListNode *p = &temp;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val <= list2->val){
                p->next = list1;
                list1 = list1->next;
            }
            else{
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        if(list1 != nullptr){
            p->next = list1;
        }
        if(list2 != nullptr){
            p->next = list2;
        }
        return temp.next;
    }
};
```
$$시간복잡도: O(n + m)$$
$$공간복잡도: O(1)$$

#### Recursion
```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
    public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) {
            return list2;
        }
        if (!list2) {
            return list1;
        }
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};
```
```plaintext
한쪽 리스트가 비어있다면, 다른 리스트를 반환합니다. 더 이상 병합할 것이 없기 때문입니다.
list1과 list2의 헤드 값을 비교합니다:
    list1.val <= list2.val 인 경우: list1.next를 남은 노드들의 병합 결과로 설정합니다. list1을 현재의 헤드로 반환합니다.
    그렇지 않은 경우: list2.next를 남은 노드들의 병합 결과로 설정합니다. list2를 현재의 헤드로 반환합니다.
두 리스트가 완전히 병합될 때까지 재귀가 계속됩니다.
```
$$시간복잡도: O(n + m)$$
$$공간복잡도: O(n + m)$$

## **💭 오늘의 회고**
처음에는 두 리스트의 노드를 비교하여 작은 값을 head변수로 포인트 해준 다음 오름차순으로 리스트를 변경해줬는데 이럴경우 두리스트가 비어있는 경우를 따로 만들어줘야 했다.   
temp노드를 만든 후에 이어 붙이면 쉽게 해결할 수 있다.