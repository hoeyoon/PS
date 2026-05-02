## **💻 문제 설명**
[문제링크](https://neetcode.io/problems/linked-list-cycle-detection/question)

## 연결 리스트 순환 탐지 (Linked List Cycle Detection)

**난이도: Easy, 알고리즘 종류: Hash Table, Linked List, Two Pointers**

연결 리스트의 시작점인 `head`가 주어졌을 때, 연결 리스트 안에 `순환(cycle)`이 있으면 `true`를, 그렇지 않으면 `false`를 반환하세요.

연결 리스트 내의 어떤 노드가 `next` 포인터를 따라갔을 때 다시 방문될 수 있다면 순환이 존재하는 것으로 간주합니다.

내부적으로 `index`는 순환이 시작되는 노드의 인덱스를 나타냅니다(순환이 존재할 경우). 리스트의 마지막 노드(tail)는 자신의 `next` 포인터를 `index`번째 노드에 연결합니다. 만약 `index = -1`이라면, 마지막 노드는 `null`을 가리키며 순환은 존재하지 않습니다.

**참고:** `index`는 매개변수(parameter)로 주어지지 않습니다.

---

### 예시 1:
*   **입력:** head = [1,2,3,4], index = 1
*   **출력:** true
*   **설명:** 연결 리스트에 순환이 존재하며, 마지막 노드가 1번째 노드(0부터 시작)에 연결되어 있습니다.



### 예시 2:
*   **입력:** head = [1,2], index = -1
*   **출력:** false
*   **설명:** 순환이 존재하지 않습니다.

---

### 제약 사항:
*   리스트의 길이 범위: `0 <= Length of the list <= 1000`
*   노드 값의 범위: `-1000 <= Node.val <= 1000`
*   `index`는 `-1`이거나 연결 리스트 내의 유효한 인덱스입니다.


## **💡 접근 및 설계**
unordered_set을 선언하여 노드의 정보를 저장한다.
set에 노드의 정보가 있다면 true를 리턴하고 아니라면 s에 노드의 정보를 저장한 뒤 p의 위치를 이동시킨다. p가 nullptr이면 false를 리턴한다.


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
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> s;
        ListNode *p = head;
        while(p != nullptr){
            if(s.find(p) != s.end()){
                return true;
            }
            s.insert(p);
            p = p->next;
        }
        return false;
    }
};
```
$$시간복잡도: O(n)$$
$$공간복잡도: O(n)$$

#### Fast And Slow Pointers
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
    bool hasCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                return true;
            }
        }

        return false;
    }
};
```
```plaintext
두 개의 포인터를 초기화합니다:

slow = head
fast = head

리스트를 이동합니다:
    slow는 한 단계 이동합니다.
    fast는 두 단계 이동합니다.

어느 지점에서든 slow == fast가 성립하면, 순환이 존재하는 것이므로 true를 반환합니다.
만약 fast가 끝(null 또는 fast.next가 null)에 도달하면, 순환이 존재하지 않는 것이므로 false를 반환합니다.
```
$$시간복잡도: O(n)$$
$$공간복잡도: O(1)$$
## **💭 오늘의 회고**
set 해시 테이블을 이용하여 문제를 해결하였다.
set은 중복된 값을 허용하지 않는다.