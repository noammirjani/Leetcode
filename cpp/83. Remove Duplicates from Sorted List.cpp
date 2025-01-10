// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* left = head; 
        int prevVal = head->val; 

        for (ListNode* right = head->next; right; right = right->next) {
            if (left->val != right->val){
                left->next = right;
                left = right;
            }
            else {
                left->next = nullptr; 
            }
        }
        return head; 
    }
};