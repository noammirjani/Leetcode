class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:        
        combine_list = []
        current = []

        def backtrack(start):
            if len(current) == k:
                combine_list.append(current[:])
                return 
            
            for i in range(start, n+1):
                current.append(i)
                backtrack(i+1)
                current.pop()
        
        backtrack(1)
        return combine_list
        
            
