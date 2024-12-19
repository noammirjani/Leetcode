# input - list of positive integers
# output - integer
# return the second-largest element from the list. If the second-largest element does not exist, return -1.


from typing import List


class Solution:
    # @staticmethod
    # def find_second_largest(nums: List[int]) -> int:
    #     # complexity: run - O(nlogn) space: O(1)
    #     if len(nums) < 2:
    #         return -1
    #     arr.sort()
    #     return arr[-2]

    @staticmethod
    def find_second_largest(nums: List[int]) -> int:
        # complexity: run - O(n) space: O(1)
        first, second = -1, -1
        for num in nums:
            if num > first:
                second = first
                first = num
            elif num > second and num != first:
                second = num
        return second


if __name__ == "__main__":
    sol = Solution()
    arr = [3, 4, 2, 1, 6, 10]
    print(sol.find_second_largest(arr))  # 4

    arr = [2, 2, 2]
    print(sol.find_second_largest(arr))  # -1

    arr = [2, 1, 2]
    print(sol.find_second_largest(arr))  # 1
