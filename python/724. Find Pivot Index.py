from typing import List


class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        left, total = 0, sum(nums)

        for i in range(len(nums)):
            if left == total - left - nums[i]:
                return i
            left += nums[i]
        return -1
