class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:        
        def dfs(target):
            if visted[target] == 1:
                return False
            if visted[target] == 2:
                return True
            
            visted[target] = 1
            for adj in adj_list[target]:
                if not dfs(adj):
                    return False   
            visted[target] = 2
            res.append(target)
            return True

        adj_list = {i: [] for i in range(numCourses)}
        for dest, src in prerequisites:
            adj_list[src].append(dest)
        res = []
        visted = [ 0 ] * numCourses
        for i in range(numCourses):
            if visted[i] == 0:
                if not dfs(i):
                    return []
        res.reverse()
        return res


        