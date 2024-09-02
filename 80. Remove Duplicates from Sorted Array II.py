from typing import List


class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        left = 1

        for right in range(2, len(nums)):
            if nums[left - 1] != nums[right]:
                left += 1
                nums[left] = nums[right]

        return left + 1


if __name__ == "__main__":
    nums = [1, 1, 1, 2, 2, 3]
    length = Solution().removeDuplicates(nums)
    print(nums[: length])
