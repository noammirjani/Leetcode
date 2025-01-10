from typing import List


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        def dfs(row, col, index):
            if index == len(word):
                return True
            if row < 0 or row >= len(board) or col < 0 or col >= len(board[0]):
                return False
            if board[row][col] != word[index]:
                return False

            temp, board[row][col] = board[row][col], '#'
            found = dfs(row, col+1, index+1) or dfs(row, col-1, index+1) or \
                    dfs(row+1, col, index+1) or dfs(row-1, col, index+1)
            board[row][col] = temp
            return found

        for i in range(len(board)):
            for j in range(len(board[0])):
                if dfs(i, j, 0):
                    return True
        return False


# Time complexity: O(N*3^L) where N is the number of cells in the board and L is the length of the word to be matched.
# Space complexity: O(L) where L is the length of the word to be matched.

if __name__ == "__main__":
    mat = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    print(Solution().exist(mat, "ABCCED"))

    mat = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    print(Solution().exist(mat, "SEE"))

    mat = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
    print(Solution().exist(mat, "ABCB"))
    