from typing import List


class Solution:
    @staticmethod
    def minimum_total_1(triangle: List[List[int]]) -> int:
        for i in range(1, len(triangle)):
            for j in range(len(triangle[i])):
                if j == 0:
                    triangle[i][j] += triangle[i-1][j]
                elif j >= len(triangle[i-1]):
                    triangle[i][j] += triangle[i-1][j-1]
                else:
                    triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1])
        return min(triangle[-1])

    @staticmethod
    def minimum_total_2(triangle: List[List[int]]):
        for i in range(len(triangle), -1, -1):
            print(triangle[i])
        return -99


if __name__ == "__main__":
    s = Solution()
    print(s.minimum_total_2([[2], [3, 4], [6, 5, 7], [4, 1, 8, 3]]))  # 11
