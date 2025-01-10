struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    //space O1
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, curr = 0;
        ListNode *dummy = new ListNode(), *res = dummy; 

        while (l1 || l2) {
            curr = carry + (l1 ? l1->val : 0) +(l2 ? l2->val : 0);
            res->next = l1 ? l1 : l2;
            res->next->val = curr % 10; 
            carry = curr / 10; 
            if (l1) l1 = l1->next; 
            if (l2) l2 = l2->next; 
            res = res->next; 
        }
        if (carry) res->next = new ListNode(carry); 
        return dummy->next; 
    }

    // space ON
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *res = dummy;

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            res->next = new ListNode(sum % 10);
            res = res->next;

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return dummy->next;
    }
};