class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        freq = [0] * 26
        for c in s:
            freq[ord(c) - ord("a")] += 1

        is_found = [False] * 26
        stack = []
        for c in s:
            index = ord(c) - ord("a")
            freq[index] -= 1
            if is_found[index]:
                continue
            while stack and stack[-1] > c and freq[ord(stack[-1]) - ord("a")] > 0:
                is_found[ord(stack[-1]) - ord("a")] = False
                stack.pop()
            stack.append(c)
            is_found[index] = True

        return "".join(stack)
