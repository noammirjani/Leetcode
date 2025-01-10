class Solution:
    def reverseWords1(self, s: str) -> str:
        words = s.split()
        for i in range(len(words)//2):
            words[i], words[len(words)-i-1] = words[len(words)-i-1], words[i]
        return " ".join(words)

    def reverseWords2(self, s: str) -> str:
        words = s.split()
        left, right = 0, len(words)-1

        while left < right:
            words[left], words[right] = words[right], words[left]
            left, right = left+1, right-1
        return " ".join(words)

    def reverseWords3(self, s: str) -> str:
        return " ".join(reversed(s.split()))