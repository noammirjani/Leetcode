class Solution:
    def isPalindrome2(self, x: int) -> bool:
        return str(x) == str(x)[::-1]

    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        copy = x
        reversed_x = 0
        while copy > 0:
            reversed_x = reversed_x * 10 + (copy % 10)
            copy //= 10
        return reversed_x == x

    # Optimal time complexity: O(n)
    # Optimal space complexity: O(1)
