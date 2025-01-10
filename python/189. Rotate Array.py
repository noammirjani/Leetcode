from typing import List


class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # time O(n) space O(n
        # k = k % len(nums)
        # remain = len(nums)-k
        # temp = nums[:remain]
        # nums[ : k] =  nums[remain:]
        # nums[k : ] = temp

        # k = k % len(nums)
        # remain = len(nums)-k
        # nums[ : ] = nums[remain:] + nums[:remain]

        k %= len(nums)
        nums[ : ] = nums[-k:] + nums[:-k]


if __name__ == "__main__":
    solution = Solution()
    nums = [1,2,3,4,5,6,7]
    solution.rotate(nums, 3)
    print(nums)
