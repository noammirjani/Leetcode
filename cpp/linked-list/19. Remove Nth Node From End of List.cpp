struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {   
        ListNode dummy = ListNode(0,head), *prev = &dummy, *curr = &dummy; 

        for (int i = 0; i <= n; ++i) {
            curr = curr->next;
        }
        while(curr) {
            prev = prev->next;
            curr = curr->next;
        }
        prev->next = prev->next->next; 
        return dummy.next; 
    }
};