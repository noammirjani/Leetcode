class Solution:
    def simplifyPath(self, path: str) -> str:
        stack = []
        for temp in path.split("/"):
            if temp == "..":
                if stack:
                    stack.pop()
            elif temp != "." and temp != "":
                stack.append(temp)
        return "/" + ("/".join(stack) if stack else "")
