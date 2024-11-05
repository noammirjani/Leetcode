class Solution:
    def lengthOfLongestSubstring_1(self, s: str) -> int:
        current = ""
        max_len = 0

        for letter in s:
            if letter not in current:
                current += letter
            else:
                for i in range(len(current)):
                    if current[i] == letter:
                        current = current[i + 1 :]
                        current += letter
                        break
            max_len = max(max_len, len(current))
        return max_len

    def lengthOfLongestSubstring_2(self, s: str) -> int:
        current = ""
        longest = 0

        for letter in s:
            right = 0
            while letter in current:
                right += 1
            current = current[right:]
            current += letter
            longest = max(longest, len(current))
        return longest

    def lengthOfLongestSubstring_3(self, s: str) -> int:
        current = ""
        longest = 0

        for letter in s:
            while letter in current:
                current = current[1:]
            current += letter
            longest = max(longest, len(current))
        return longest
