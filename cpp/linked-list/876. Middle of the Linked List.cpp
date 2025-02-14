
struct ListNode {
     int val;
     ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        for(ListNode* temp = head; temp; temp = temp->next) len++;
        ListNode* halfPtr = head;
        len /=2;
        while (len > 0){
            len--;
            halfPtr = halfPtr->next;
        }
        return halfPtr;
    }
};