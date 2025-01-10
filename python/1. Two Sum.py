from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        remains = {}
        for i, num in enumerate(nums):
            if target-num in remains:
                return [i, remains[target-num]]
            remains[num] = i
        return []


if __name__ == '__main__':
    s = Solution()
    print(s.twoSum([2,7,11,15], 9))  # [0, 1]
    print(s.twoSum([3,2,4], 6))  # [1, 2]
    