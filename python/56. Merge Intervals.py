from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        start = 0
        end = 1
        intervals.sort(key=lambda x: x[start])  # by the first val
        stack = [intervals[0]]
        for i in intervals[1:]:
            if i[start] <= stack[-1][end]:
                stack[-1][end] = max(stack[-1][end], i[end])
            else:
                stack.append(i)
        return stack


# Optimal time complexity: O(n log n) (can't do better due to sorting).
# Space complexity: O(n) in the worst case.
