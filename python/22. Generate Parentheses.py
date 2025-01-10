# medium 

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def generate(current, open_count, close_count):
            if len(current) == 2*n:
                parenthesis.append(current)
                return 
            if close_count > open_count:
                return

            if open_count < n:
                generate(current + "(", open_count+1, close_count)
            if close_count < n:
                generate(current + ")", open_count, close_count+1)

        parenthesis = []
        generate("", 0, 0)
        return parenthesis
