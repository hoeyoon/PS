#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
