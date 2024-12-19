from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        largest = nums[0]
        curr = nums[0]

        for num in nums[1:]:
            curr = max(num, curr+num)
            largest = max(curr, largest)
        return largest
