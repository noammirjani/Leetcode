class Solution:
    def romanToInt(self, s: str) -> int:
        weights = {'I': 1, 'V': 5, 'X': 10, 'L':50, 'C':100, 'D':500, 'M': 1000}
        amount = 0
        prev_val = 0
        for i in range(len(s)-1, -1, -1):
            char_val = weights[s[i]]
            if char_val >= prev_val:
                amount += char_val 
            else:
                amount -= char_val
            prev_val = char_val
        return amount
    
    
if __name__ == '__main__':
    s = Solution()
    print(s.romanToInt("III"))  # 3
    print(s.romanToInt("IV"))  # 4
    print(s.romanToInt("IX"))  # 9
    print(s.romanToInt("LVIII"))  # 58
    print(s.romanToInt("MCMXCIV"))  # 1994
    