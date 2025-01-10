from typing import Optional


class ListNode:
    # Definition for singly-linked list.
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def reverseList(head: Optional[ListNode]) -> Optional[ListNode]:
    prev = None
    curr = head
    while curr:
        next_temp = curr.next
        curr.next = prev
        prev = curr
        curr = next_temp
    return prev


def print_list(head: Optional[ListNode]):
    """Helper function to print the linked list."""
    curr = head
    while curr:
        print(curr.val, end=" -> " if curr.next else "\n")
        curr = curr.next


if __name__ == '__main__':
    # Create a linked list from the nums array
    nums = [1, 2, 3, 4, 5]
    if nums:
        nodes = ListNode(nums[0])
        curr = nodes
        for i in range(1, len(nums)):
            curr.next = ListNode(nums[i])
            curr = curr.next

        print("Original list:")
        print_list(nodes)  # Print the original list

        reversed_list = reverseList(nodes)
        print("Reversed list:")
        print_list(reversed_list)  # Print the reversed list
    else:
        print("Empty list")
