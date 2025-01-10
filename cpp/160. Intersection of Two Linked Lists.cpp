#include <cstdlib>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p2a = headA, *p2b = headB;
        while(p2a != p2b){
            p2a = p2a ? p2a->next : headA;
            p2b = p2b ? p2b->next : headB;
        }
        return p2a;
    }

    ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
        
        int lenA = 0;
        ListNode * p2A = headA;
        while(p2A){
            p2A=p2A->next;
            lenA++;
        }
        int lenB = 0;
        ListNode * p2B = headB;
        while(p2B){
            p2B=p2B->next;
            lenB++;
        }
        p2A = headA;
        p2B = headB;
        for(int i = 0; i < std::abs(lenB-lenA); i++){
            if(lenB>lenA){
                p2B =p2B->next;
            }
            else{
                p2A =p2A->next;
            }
        }

        while(p2B && p2A){
            if(p2A == p2B) return p2A;
            p2A = p2A->next;
            p2B = p2B->next;
        }
        return nullptr;
    }
};