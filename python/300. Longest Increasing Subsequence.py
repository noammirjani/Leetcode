from typing import List


def lengthOfLIS(nums: List[int]) -> int:
    dp = [1] * len(nums)    # holds the current length to each cell

    for i in range(1,len(nums)):
        for j in range(i):
            if nums[j] < nums[i]:
                dp[i] = max(dp[i], dp[j]+1)
    return max(dp)          # maximum val does not sure to be in the last element


# Time complexity: O(n^2)
# Space complexity: O(n)

if __name__ == "__main__":
    print(lengthOfLIS([10,9,2,5,3,7,101,18])) # 4
    print(lengthOfLIS([0,1,0,3,2,3])) # 4
    print(lengthOfLIS([7,7,7,7,7,7,7])) # 1
