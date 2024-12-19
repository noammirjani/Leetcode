# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


from typing import Optional


class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0
        dummy = ListNode(0)
        newList = dummy

        while l1 or l2 or carry:
            val1, val2 = 0,0

            if l1:
                val1 = l1.val
                l1 = l1.next
            if l2:
                val2 = l2.val
                l2 = l2.next

            sum = val1 + val2 + carry
            carry = sum // 10
            newList.next = ListNode(sum % 10)
            newList = newList.next
        return dummy.next


