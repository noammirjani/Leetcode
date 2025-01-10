

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        if not nums:
            return []
        ranges = []
        start = nums[0]
        for i in range(1, len(nums)):
            if not nums[i]-1 == nums[i-1]:
                ranges.append(f"{start}->{nums[i-1]}" if start != nums[i-1] else f"{start}")
                start = nums[i]
        ranges.append(f"{start}->{nums[-1]}" if start != nums[-1] else f"{start}")
        return ranges