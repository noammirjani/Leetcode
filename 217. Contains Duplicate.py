# Problem: 217. Contains Duplicate
from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(set(nums)) != len(nums)
    
    # def containsDuplicate(self, nums: List[int]) -> bool:
        # values = {}
        # for num in nums:
        #     if num in values:
        #         return True
        #     else:
        #         values[num] = False
        # return False

    # def containsDuplicate(self, nums: List[int]) -> bool:
    #     nums.sort()
    #     for i in range(1, len(nums)):
    #         if nums[i-1] == nums[i]:
    #             return True
    #     return False


if __name__ == '__main__':
    s = Solution()
    print(s.containsDuplicate([1,2,3,1]))  # True
    print(s.containsDuplicate([1,2,3,4]))  # False
