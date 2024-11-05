# Given an array of strings strs, group the anagrams together.
# You can return the answer in any order.

from typing import List


class Solution:
    @staticmethod
    def group_anagrams1(self, strs: List[str]) -> List[List[str]]:
        # run complexity: O(n * m * log(m))
        # space complexity: O(n * m)
        roots = {}

        for word in strs:
            root = tuple(sorted(word))
            roots[root] = roots.get(root, []) + [word]
        return list(roots.values())

    @staticmethod
    def group_anagrams2(self, strs: List[str]) -> List[List[str]]:
        # run complexity: O(n * m)
        # space complexity: O(n * m)
        roots = {}
        for word in strs:
            freq = [0] * 26
            for x in word:
                freq[ord(x)-ord('a')] += 1
            roots[tuple(freq)] = roots.get(tuple(freq), []) + [word]
        return list(roots.values())

