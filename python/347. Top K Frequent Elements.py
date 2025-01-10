from typing import List
from collections import Counter
import heapq

# using Counter - O(n) time complexity and O(n) space complexity
def topKFrequent_1(nums: List[int], k: int) -> List[int]:
    count = Counter(nums)
    return [key for key, _ in count.most_common(k)]


# using heap (heapq) - O(nlogk) time complexity and O(n) space complexity
def topKFrequent_2(nums: List[int], k: int) -> List[int]:
    freq = {}
    for num in nums:
        freq[num] = freq.get(num, 0) + 1

    heap = []
    for key, val in freq.items():
        heapq.heappush(heap, (val, key))
        if len(heap) > k:
            heapq.heappop(heap)

    return [key for val, key in heap]


# bucket sort - O(n) time complexity and O(n) space complexity
def topKFrequent(nums: List[int], k: int) -> List[int]:
    freq = {}
    for num in nums:
        freq[num] = freq.get(num, 0) + 1

    buckets = [[] for _ in range(len(nums)+1)]
    for key, val in freq.items():
        buckets[len(nums) - val].append(key)

    res = []
    for bucket in buckets:
        for num in bucket:
            res.append(num)
            if len(res) == k:
                return res


if __name__ == "__main__":
    print(topKFrequent([1, 1, 1, 2, 2, 3], 2))  # [1,2]
    print(topKFrequent([1], 1))  # [1]
    print(topKFrequent([1, 2], 2))  # [1,2]
