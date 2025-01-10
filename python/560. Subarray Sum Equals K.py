from typing import List


class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        current, subarrays = 0, 0
        sums_map = {0: 1}

        for num in nums:
            current += num
            if current-k in sums_map:
                subarrays += sums_map[current-k]
            sums_map[current] = sums_map.get(current, 0) + 1
        return subarrays

    def subarraySum_brute_force(self, nums: List[int], k: int) -> int:
        current = 0
        subarrays = 0
        for i in range(len(nums)):
            current = nums[i]
            if current == k:
                subarrays += 1
            for j in range(i+1, len(nums)):
                current += nums[j]
                if current == k:
                    subarrays += 1
        return subarrays

