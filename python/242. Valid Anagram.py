class Solution:
    # time complexity: O(n) space complexity: O(n)
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False 
        letters = {}
        for char in s:
            letters[char] = letters.get(char, 0) + 1
        for char in t:
            if char not in letters or letters[char] == 0:
                return False 
            letters[char] -= 1
        return True
    
    #t ime complexity: O(n) space complexity: O(n)
    def isAnagram(self, s: str, t: str) -> bool:
        S, T = {}, {}
        for char in s:
            S[char] = S.get(char, 0) + 1
        for char in t:
            T[char] = T.get(char, 0) + 1
        return S == T

    # time complexity: O(nlogn) space complexity: O(1)
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
    
    # time complexity: O(n) space complexity: O(1)
    def isAnagram(self, s: str, t: str) -> bool:
        letters = [0] * 26
        for char in s:
            letters[ord(char) - ord('a')] += 1
        for char in t:
            letters[ord(char) - ord('a')] -= 1
        for count in letters:
            if count != 0:
                return False
        return True

if __name__ == '__main__':
    s = Solution()
    print(s.isAnagram("anagram", "nagaram"))  # True
    print(s.isAnagram("rat", "car"))  # False
    print(s.isAnagram("ab", "a"))  # False
    print(s.isAnagram("a", "a"))  # True
    print(s.isAnagram("a", "b"))  # False
    