struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;

        ListNode dummy(0, head), *prev=&dummy;

        //move to start of range
        for (int i = 1; i < left; ++i) prev = prev->next; 

        ListNode *curr = prev->next, *nextNode = nullptr; 

        for (int i = 0; i < right - left; i++) {
            nextNode = curr->next;
            curr->next = nextNode->next;
            nextNode->next = prev->next; 
            prev->next = nextNode;
        }

        return dummy.next;
    }
};