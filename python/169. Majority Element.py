from typing import List


class Solution:
    # def majorityElement(self, nums: List[int]) -> int:
    #     # time - O(n) space - O(n)
    #     counts = {}
    #
    #     for x in nums:
    #         temp = counts.get(x, 0) + 1
    #         if temp > len(nums) / 2:
    #             return x
    #         counts[x] = temp


    def majorityElement(self, nums: List[int]) -> int:
        # time - O(n) space - O(1)
        candidate, count = 0, 0

        for x in nums:
            if count == 0:
                candidate = x
                count = 1
            elif x == candidate:
                count += 1
            else:
                count -= 1
        return candidate


if "__main__" == __name__:
    solution = Solution()
    print(solution.majorityElement([3,3,2]))
    print(solution.majorityElement([2,2,2,1,1,1,2,]))
