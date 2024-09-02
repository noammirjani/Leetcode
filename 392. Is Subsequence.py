class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        j = 0
        for i in range(len(t)):
            j += (j < len(s) and s[j] == t[i])
        return j == len(s)


if "__main__" == __name__:
    solution = Solution()
    print(solution.isSubsequence("", "sdhjd"))
