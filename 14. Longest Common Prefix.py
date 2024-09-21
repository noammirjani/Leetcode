from typing import List

# first approach - vertical scanning
# time complexity: O(n*m) where n is the number of strings and m is the length of the smallest string
# space complexity: O(n*m) due to repeated substring creation
# def longestCommonPrefix(strs: List[str]) -> str:
#     if not strs:
#        return ""
#     for i in range(len(strs[0])):
#         for word in strs[1:]:
#             if len(word) <= i or word[: i] != strs[0][: i]:
#                 return strs[0][: i]
#     return strs[0]


# second approach - sort the strings and compare the first and last string
# time complexity: O(nlogn + m) where n is the number of strings and m is the length of the smallest string
# space complexity: O(n) due to sorting not in-place -> O(1) if in-place with sort()
# def longestCommonPrefix(strs: List[str]) -> str:
#     x = sorted(strs)
#     prefix = ""
#     for i in range(len(x[0])):
#         if x[0][i] != x[-1][i]:
#             return prefix
#         prefix += x[0][i]
#     return prefix


# third approach - horizontal scanning
# time complexity: O(n*m) where n is the number of strings and m is the length of the smallest string
# space complexity: O(1) due to startswith() method
def longestCommonPrefix(strs: List[str]) -> str:
    if not strs:
        return ""
    prefix = strs[0]
    for word in strs[1:]:
        while word.startswith(prefix) != 0:
            prefix = prefix[:-1]
            if not prefix:
                return ""


if __name__ == '__main__':
    print(longestCommonPrefix(["flower", "flow", "flight"]))  # "fl"
