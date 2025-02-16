class Solution:
    def maxDepth(self, s: str) -> int:
        current = 0
        count = 0
        for c in s:
            if c == "(":
                current += 1
            elif c == ")":
                current -= 1
            count = max(count, current)
        return count


# Optimal time complexity: O(n)
# Optimal space complexity: O(1)
