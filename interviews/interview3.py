"""payoneer"""

import heapq


def find_kth_largest(nums, k):
    # Create a min heap with the first k elements
    min_heap = nums[:k]
    heapq.heapify(min_heap)

    # Process the rest of the elements
    for num in nums[k:]:
        if num > min_heap[0]:
            heapq.heappushpop(min_heap, num)

    # The root of the heap is the kth largest element
    return min_heap[0]


# Example usage:
nums = [3, 2, 1, 5, 6, 4]
k = 2
print(find_kth_largest(nums, k))  # Output: 5
