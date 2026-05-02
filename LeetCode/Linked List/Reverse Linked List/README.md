## **💻 문제 설명**
[문제링크](https://neetcode.io/problems/reverse-a-linked-list/question)

## Reverse Linked List (연결 리스트 뒤집기)
**난이도: Easy, 알고리즘 종류: Linked List, Recursion**

단일 연결 리스트의 시작 지점인 `head`가 주어졌을 때, 리스트를 뒤집어서 새로운 시작 지점을 반환하세요.

**예시 1:**
*   **입력:** head = [0,1,2,3]
*   **출력:** [3,2,1,0]



**예시 2:**
*   **입력:** head = []
*   **출력:** []

**제약 사항:**
*   리스트의 길이는 0 이상 1000 이하입니다.
*   노드의 값(`Node.val`)은 -1000 이상 1000 이하입니다.


## **💡 접근 및 설계**
ListNode 포인터 변수 p, q, r을 선언한다.  
p는 역순으로 만들 리스트이다.
q는 현재 역순으로 만들 노드를 가리킨다.  
r은 이미 역순으로 변경된 리스트를 가리킨다.  
r은 q, q는 p를 차례로 따라간다.


### **✏️ 알고리즘 풀이**
#### 나의 풀이
```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p, *q, *r;

        p = head;
        q = nullptr;
        while(p != nullptr){
            r = q;

            q = p;
            p = p->next;
            q->next = r;
        }
        return q;
    }
};
```
$$시간복잡도: O(n)$$
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
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return nullptr;
        }

        ListNode* newHead = head;
        if (head->next) {
            newHead = reverseList(head->next);
            head->next->next = head;
        }
        head->next = nullptr;

        return newHead;
    }
};
```
```plaintext
리스트가 비어 있으면 null을 반환합니다.
head.next에 대해 함수를 재귀적으로 호출하여 리스트의 나머지 부분을 뒤집습니다.
재귀 호출이 반환된 후:
    head.next.next = head로 설정하여 다음 노드가 현재 노드를 다시 가리키게 만듭니다.
    순환(cycle)을 방지하기 위해 head.next = null로 설정합니다.
가장 깊은 재귀 호출에서 반환된 새로운 시작점(new head)을 반환합니다.
```
$$시간복잡도: O(n)$$
$$공간복잡도: O(n)$$
## **💭 오늘의 회고**
대학교 데이터구조 수업 때 배운 연결리스트를 뒤집는 코드를 만들어봤다. 재귀함수를 사용해서 풀 수도 있다.