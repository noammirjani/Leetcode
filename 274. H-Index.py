from typing import List


class Solution:
    # def hIndex(self, citations: List[int]) -> int:
    #     # time o(nm) memory o(m)
    #     arr = [0] * (max(citations) + 1)
    #     h_index = 0
    #
    #     for i in citations:
    #         for j in range(i + 1):
    #             arr[j] += 1
    #
    #     for i in range(len(arr)):
    #         if arr[i] >= i and i > h_index:
    #             h_index = i
    #
    #     return h_index

    def hIndex(self, citations: List[int]) -> int:
        # time nlogn memory - o(1)
        citations.sort(reverse=True)
        n = len(citations)

        for i in range(n):
            if citations[i] < i + 1:
                return i
        return n


if __name__ == "__main__":
    print(Solution().hIndex([3,0,1,6,5]))
