from cmath import inf
from typing import List


class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [0] + [float(inf)] * amount

        for i in range(1, amount+1):
            for coin in coins:
                if i - coin >= 0 and dp[i-coin] != float(inf):
                    dp[i] = min(dp[i-coin]+1, dp[i])
        return dp[amount] if dp[amount] != float(inf) else -1
