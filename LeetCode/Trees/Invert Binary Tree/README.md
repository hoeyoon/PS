## **💻 문제 설명**
[문제링크](https://neetcode.io/problems/invert-a-binary-tree/question?list=blind75)

### 이진 트리 반전 (Invert Binary Tree)

이진 트리의 루트 노드 root가 주어집니다. 이진 트리를 반전시키고 그 루트 노드를 반환하세요.

#### 예시 1:   

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/ac124ee6-207f-41f6-3aaa-dfb35815f200/public)

입력: root = [1,2,3,4,5,6,7]   
출력: [1,3,2,7,6,5,4]  

#### 예시 2:

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/e39e8d4f-9946-4f99-ee3d-0d4df08d4d00/public)

입력: root = [3,2,1]   
출력: [3,1,2]

#### 예시 3:  
입력: root = []   
출력: []

#### 제약 사항:
0 <= The number of nodes in the tree <= 100   
-100 <= Node.val <= 100


## **💡 접근 및 설계**
이진 트리의 자식 노드들의 값을 서로 바꿔줘야한다.
만약 root가 nullptr이면 nullptr를 리턴한다.
자식 노드들의 값을 바꿔주고 invertTree(root->left)함수를 호출하여 왼쪽 노드에서 함수를 실행해주고 오른쪽 노드에서도 함수를 실행한다. 모든 과정이 끝나면 root를 리턴한다.


### **✏️ 알고리즘 풀이**
#### 나의 풀이(깊이 우선 탐색)
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }

        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
```
$$시간복잡도:O(n)$$
$$공간복잡도:O(n)$$
#### 2. 깊이 우선 탐색 (Depth First Search)

**직관**  
이진 트리를 반전시킨다는 것은 모든 노드의 왼쪽 서브트리와 오른쪽 서브트리를 서로 바꾸는 것을 의미합니다.
깊이 우선 탐색(DFS)을 사용하면, 재귀를 통해 탑다운(Top-down, 위에서 아래로) 방식으로 트리를 반전시킬 수 있습니다:

* 각 노드에서 왼쪽 자식과 오른쪽 자식을 서로 바꿉니다.
* 그 다음 왼쪽 서브트리를 재귀적으로 반전시킵니다.
* 오른쪽 서브트리를 재귀적으로 반전시킵니다.
모든 서브트리 그 자체도 더 작은 이진 트리이기 때문에, 재귀를 통해 이러한 구조를 자연스럽게 처리할 수 있습니다.
반전은 재귀가 아래로 내려가는 동안 일어나며, 각 서브트리는 올바르게 거울처럼 대칭이 됩니다.

**알고리즘**

* 현재 노드가 null이면 null을 반환합니다.
* 노드의 왼쪽 포인터와 오른쪽 포인터를 서로 바꿉니다.
* 새로운 왼쪽 자식에 대해 dfs를 재귀적으로 호출합니다.
* 새로운 오른쪽 자식에 대해 dfs를 재귀적으로 호출합니다.
* (이제 반전된) 현재 노드를 반환합니다.
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
```
$$시간복잡도:O(n)$$
$$공간복잡도:O(n)$$
#### 1. 너비 우선 탐색 (Breadth First Search)

**직관**  
이진 트리를 반전(거울처럼 대칭)시키려면, 모든 노드가 자신의 왼쪽 자식과 오른쪽 자식을 서로 바꾸어야 합니다. 너비 우선 탐색(BFS)을 사용하면 트리를 레벨별로 처리하게 됩니다:

* 루트 노드부터 시작합니다.
* 각 노드에 대해, 그 자식 노드들을 서로 바꿉니다.
* 그런 다음 (새로 바뀐) 왼쪽 자식과 오른쪽 자식을 큐(queue)에 넣습니다.
* 모든 노드가 처리될 때까지 이 과정을 계속합니다.
이 접근 방식은 모든 노드를 정확히 한 번씩 방문하고, 노드를 만나는 즉시 반전되도록 보장합니다.

**알고리즘**
* 트리가 비어 있다면 null을 반환합니다.
* 큐를 초기화하고 루트 노드를 삽입합니다.
* 큐가 비어 있지 않은 동안:
* 맨 앞의 노드를 꺼냅니다.
* 그 노드의 왼쪽 자식과 오른쪽 자식을 서로 바꿉니다.
* 왼쪽 자식이 존재한다면, 큐에 추가합니다.
* 오른쪽 자식이 존재한다면, 큐에 추가합니다.


* 모든 노드가 처리된 후, 반전된 트리의 루트를 반환합니다.
```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            TreeNode* node = queue.front();
            queue.pop();
            swap(node->left, node->right);
            if (node->left) queue.push(node->left);
            if (node->right) queue.push(node->right);
        }
        return root;
    }
};
```
$$시간복잡도:O(n)$$
$$공간복잡도:O(n)$$

#### 3. 반복적 깊이 우선 탐색 (Iterative DFS)

**직관**  
반복적 DFS는 재귀 대신 명시적인 스택을 사용하여 이진 트리를 반전시킵니다.
아이디어는 재귀적 DFS와 같습니다:

* 노드를 방문합니다.
* 왼쪽 자식과 오른쪽 자식을 서로 바꿉니다.
* 그 자식 노드들에 대해 이 과정을 계속합니다.
다만 콜 스택(call stack) 대신 우리가 직접 만든 스택 자료구조를 사용합니다.
과정은 다음과 같습니다:
* 루트를 스택에 넣습니다.
* 맨 위의 노드를 꺼내고(pop), 그 자식 노드들을 서로 바꿉니다.
* 자식 노드들이 존재한다면 스택에 넣습니다(push).
* 스택이 빌 때까지 이 과정을 계속합니다.
이 방식은 재귀적 DFS를 반복문 형태로 시뮬레이션하며, 재귀의 깊이가 너무 깊어질 수 있을 때 유용하게 작동합니다.

**알고리즘**

* 루트가 null이면 null을 반환합니다.
* 루트 노드로 스택을 초기화합니다.
* 스택이 비어 있지 않은 동안:
* 노드를 하나 꺼냅니다(pop).
* 노드의 왼쪽 포인터와 오른쪽 포인터를 서로 바꿉니다.
* 왼쪽 자식이 존재한다면, 스택에 넣습니다(push).
* 오른쪽 자식이 존재한다면, 스택에 넣습니다(push).

* 루트를 반환합니다.

```c++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            swap(node->left, node->right);
            if (node->left) stack.push(node->left);
            if (node->right) stack.push(node->right);
        }
        return root;
    }
};
```
$$시간복잡도:O(n)$$
$$공간복잡도:O(n)$$
## **💭 오늘의 회고**
이진트리의 자삭 노드들의 값을 swap하는 코드를 만들어봤다.
학교에서 배운 재귀함수를 사용하여 값을 바꾸고 왼쪽 노드와 오른쪽 노드의 자식 노드들도 값을 바꿔주고 노드가 없으면 nullptr를 리턴한다.  
큐와 스택을 사용하여 해결 할 수도 있다.   
큐를 사용하면 BFS를 구현할수있다. (BFS:시작 노드에서 가까운 노드부터 넓게 탐색하며 한 단계씩 퍼져나가는 그래프 탐색 알고리즘)   
스택을 사용하면 Iterative DFS(반복적 깊이 우선 탐색)를 구현 할 수 있다.