from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit, min_price = 0, prices[0]

        for i in range(1, len(prices)):
            max_profit = max(max_profit, prices[i] - min_price)
            min_price = min(prices[i], min_price)

        return max_profit


if "__main__" == __name__:
    prices = [7,1,5,3,6,4]
    sol = Solution()
    print(sol.maxProfit(prices))
