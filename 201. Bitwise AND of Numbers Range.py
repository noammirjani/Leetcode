class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        shift = 0
        while left < right:
            left >>= 1
            right >>= 1
            shift += 1
        return left << shift
    

if __name__ == "__main__":
    s = Solution()
    print(s.rangeBitwiseAnd(5, 7))  # 4
    print(s.rangeBitwiseAnd(0, 1))  # 0
    print(s.rangeBitwiseAnd(1, 2147483647))  # 0
