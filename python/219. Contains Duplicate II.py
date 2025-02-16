from typing import List


class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        data = {}
        for i in range(len(nums)):
            if nums[i] in data and abs(data[nums[i]] - i) <= k:
                return True
            data[nums[i]] = i
        return False
