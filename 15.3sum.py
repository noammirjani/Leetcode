from typing import List


def three_sum(nums: List[int]) -> List[List[int]]:
    res = []
    nums.sort()

    for i in range(len(nums)-2):
        if i > 0 and nums[i] == nums[i-1]:
            continue

        target = -nums[i]
        left, right = i+1, len(nums)-1
        while left < right:
            curr_sum = nums[left] + nums[right]
            if curr_sum == target:
                res.append([nums[i], nums[left], nums[right]])
                while left < right and nums[left] == nums[left+1]:
                    left += 1
                while left < right and nums[right] == nums[right-1]:
                    right -= 1
                left += 1
                right -= 1
            elif curr_sum < target:
                left += 1
            else:
                right -= 1
    return res


if __name__ == "__main__":
    print(three_sum([0, 0, 0]))
    print(three_sum([-1, 0, 1, 2, -1, -4]))
