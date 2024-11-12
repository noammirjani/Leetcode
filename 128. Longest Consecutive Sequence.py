from typing import List


class Solution:
    def longestConsecutive_1(self, nums: List[int]) -> int:
        """
        run time: O(nlogn)
        space: O(1)
        """
        nums.sort()
        longest = 1
        curr_long = 1
        for i in range(1, len(nums)):
            if nums[i] == nums[i-1] + 1:
                curr_long += 1
            else:
                curr_long = 1
            longest = max(longest, curr_long)
        return longest

    def longestConsecutive_2(self, nums: list[int]) -> int:
        """
        run time: O(n)
        space: O(n)
        """
        seq = {}
        longest = 0

        for num in nums:
            if num in seq:
                continue

            left = seq.get(num - 1, 0)
            right = seq.get(num + 1, 0)
            current_length = 1 + left + right

            seq[num] = current_length
            seq[num - left] = current_length  # Update start of the sequence
            seq[num + right] = current_length  # Update end of the sequence

            longest = max(longest, current_length)

        return longest

    def longestConsecutive_3(self, nums: list[int]) -> int:
        """
        run time: O(n)
        space: O(n)
        """
        nums_set = set(nums)
        longest = 0
        for num in nums_set:
            if num-1 not in nums_set:
                curr_num = num
                curr_long = 1
                while curr_num + 1 in nums_set:
                    curr_num += 1
                    curr_long += 1
                longest = max(longest, curr_long)
        return longest


if __name__ == "__main__":
    sol = Solution()
    print(sol.longestConsecutive_3([100, 4, 200, 1, 3, 2]))  # 4
    print(sol.longestConsecutive_3([100, 4, 101]))  # 2
