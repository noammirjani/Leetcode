class Solution:
    import heapq

    def connectSticks(self, sticks: List[int]) -> int:
        heapq.heapify(sticks)
        total = 0

        while len(sticks) > 1:
            first = heapq.heappop(sticks)
            second = heapq.heappop(sticks)
            cost = first + second
            heapq.heappush(sticks, cost)
            total += cost
        return total
