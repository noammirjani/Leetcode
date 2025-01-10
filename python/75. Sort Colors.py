def sortColors(nums: List[int]) -> None:
    arr = [0, 0, 0]
    index = 0
    for num in nums:
        arr[num] += 1
    for i in range(len(arr)):
        while arr[i] > 0:
            nums[index] = i
            arr[i] -= 1
            index += 1


def sortColors(nums: List[int]) -> None:
    low, mid, high = 0, 0, len(nums) - 1

    while mid <= high:
        if nums[mid] == 0:
            nums[low], nums[mid] = nums[mid], nums[low]
            low += 1
            mid += 1
        elif nums[mid] == 1:
            mid += 1
        else:
            nums[high], nums[mid] = nums[mid], nums[high]
            high -= 1
