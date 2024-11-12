from typing import List


class Solution:
    """
    t[i] =
        nums[0]                             if i == 0
        max(nums[0], nums[1])               if i == 1
        max(t[i-2] + nums[i], t[i-1])       otherwise
    """
    def rob(self, nums: List[int]) -> int:
        best = [nums[0]]

        if len(nums) > 1:
            best.append(max(nums[0],nums[1]))

        for i in range(2, len(nums)):
            best.append(max(best[i-2] + nums[i], best[i-1]))
        return best[-1]


if __name__ == "__main__":
    sol = Solution()
    print(sol.rob([1,2,3,1]))  # 4
    print(sol.rob([2,7,9,3,1]))  # 12
