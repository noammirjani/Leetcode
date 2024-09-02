from typing import List


class Solution:
    # def removeElement(self, nums: List[int], val: int) -> int:
    #     k = 0
    #     i, j = 0, len(nums) - 1
    #
    #     while i <= j:
    #         if nums[j] == val:
    #             j -= 1
    #         elif nums[i] != val:
    #             i += 1
    #             k += 1
    #         else:
    #             nums[i] = nums[j]
    #             nums[j] = val
    #             i += 1
    #             j -= 1
    #             k += 1
    #     return k

    def removeElement(self, nums: List[int], val: int) -> int:
        left = 0

        for right in range(len(nums)):
            if nums[right] != val:
                nums[left] = nums[right]
                left += 1
        return left


if __name__ == "__main__":
    arr = [3, 2, 2, 3]
    length = Solution().removeElement(arr, 3)
    print(length, arr[:length])
