from typing import List

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        xor = nums[0]
        for num in nums[1:]:
            xor ^= num
        return xor

# time complexity: O(n) space complexity: O(1)