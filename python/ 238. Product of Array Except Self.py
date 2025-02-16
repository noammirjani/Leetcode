from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        # time - ON^2 space -o1
        # answer = [1] * len(nums)
        # for i in range(len(nums)):
        #     for j in range(len(nums)):
        #         if i != j:
        #             answer[i] *= nums[j]
        # return answer

        # time - ON space -ON
        # left = [1] * len(nums)
        # for i in range(1, len(nums)):
        #     left[i] = (left[i-1] * nums[i-1])
        # right = [1] * len(nums)
        # for i in range(len(nums)-2, -1, -1):
        #     right[i] = (right[i+1] * nums[i+1])
        # return [l*r for (l,r) in zip(left,right)]
        # example = [1,2,3,4]
        # left    = [1, 1, 2,6] each cell holds the multiplication of all the value from its left
        # right   = [24,12,4,1] each cell holds the multiplication of all the values from its right
        # answer  = [24,12,8,6] each cell multiplies the left to each cell and the right to each cell

        # time - ON space -O1 (but the answer list that is mentioned in the description)
        answer = [1] * len(nums)
        for i in range(1, len(nums)):
            answer[i] = answer[i - 1] * nums[i - 1]
        prev = 1
        for i in range(len(nums) - 1, -1, -1):
            answer[i] = answer[i] * prev
            prev *= nums[i]
        return answer
