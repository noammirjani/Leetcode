class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        """
        run - On
        space - On
        """
        words = s.split()

        if len(pattern) != len(words):
            return False

        pattern_to_word, pattern_to_word = {}, {}
        for char, word in zip(pattern, words):
            if char in pattern_to_word and pattern_to_word[char] != word:
                return False
            if word in pattern_to_word and pattern_to_word[word] != char:
                return False
            pattern_to_word[char], pattern_to_word[word] = word, char
        return True


if __name__ == "__main__":
    sol = Solution()
    print(sol.wordPattern("abba", "dog cat cat dog"))  # True
    print(sol.wordPattern("abba", "dog cat cat fish"))  # False
    print(sol.wordPattern("aaaa", "dog cat cat dog"))  # False
    print(sol.wordPattern("abba", "dog dog dog dog"))  # False
