class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        target = {}
        source = {}
        for i in range(len(s)):
            if s[i] in source and source[s[i]] != t[i]:
                return False
            elif t[i] in target and target[t[i]] != s[i]:
                return False
            else:
                source[s[i]] = t[i]
                target[t[i]] = s[i]                
        return True