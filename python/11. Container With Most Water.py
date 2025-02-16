from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        # max_area  = 0
        # for i in range(len(height)):
        #     for j in range(i+1, len(height)):
        #         max_area = max( (j-i) * min(height[i],height[j]) , max_area)
        # return max_area

        max_area = 0
        left = 0
        right = len(height) - 1
        while left < right:
            max_area = max((right - left) * min(height[right], height[left]), max_area)
            if height[left] < height[right]:
                left += 1
            else:
                right -= 1
        return max_area
