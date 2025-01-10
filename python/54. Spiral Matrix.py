class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        result = []
        left, right, up, down = 0, len(matrix[0]), 0, len(matrix)
        while left < right and down > up:
            for i in range(left, right):          #up
                result.append(matrix[up][i])
            up += 1
            for i in range(up, down):             #right
                result.append(matrix[i][right-1])
            right -= 1
            if not (left < right and up < down):
                break
            for i in range(right-1, left-1, -1):  #down
                result.append(matrix[down-1][i])
            down -= 1
            for i in range(down-1, up-1 , -1):     #left
                result.append(matrix[i][left])
            left += 1
            print(left, right, up, down)            
        return result
