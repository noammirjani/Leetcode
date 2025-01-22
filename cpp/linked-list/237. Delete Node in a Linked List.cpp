
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node || !node->next) return; 

        auto nextNode = node->next; 
        node->val = nextNode->val; 
        node->next = nextNode->next;
        delete nextNode;         
    }
};