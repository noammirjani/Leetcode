"""
Implement a trie with insert, search, and startsWith methods with
O(m) time complexity, where m is the key length.
"""


class Trie:
    def __init__(self):
        """Initialize the Trie with an empty dictionary to store nodes."""
        self.data = {}

    def insert(self, word: str) -> None:
        """Inserts a word into the trie."""
        node_data = self.data
        for s in word:
            node_data = node_data.setdefault(s, {})
        node_data['end_word'] = True

    def search(self, word: str) -> bool:
        """Returns True if the word is in the trie, False otherwise."""
        node_data = self.data
        for s in word:
            if s not in node_data:
                return False
            node_data = node_data[s]
        return 'end_word' in node_data

    def starts_with(self, prefix: str) -> bool:
        """Returns True if there is any word in the trie that starts with the given prefix."""
        node_data = self.data
        for s in prefix:
            if s not in node_data:
                return False
            node_data = node_data[s]
        return True


if __name__ == "__main__":
    trie = Trie()
    trie.insert("apple")
    print(trie.search("apple"))  # True
    print(trie.search("app"))  # False
    print(trie.starts_with("app"))  # True
    trie.insert("app")
    print(trie.search("app"))  # True


# Alternative implementation - using TrieNode class:
# class TrieNode:
#     def __init__(self):
#         self.data = {}
#         self.end_word = False
#
#
# class Trie:
#     def __init__(self):
#         self.root = TrieNode()
#
#     def insert(self, word: str) -> None:
#         node = self.root
#         for s in word:
#             if s not in node.data:
#                 node.data[s] = TrieNode()
#             node = node.data[s]
#         node.end_word = True
#
#     def search(self, word: str) -> bool:
#         node = self.root
#         for s in word:
#             if s not in node.data:
#                 return False
#             node = node.data[s]
#         return node.end_word
#
#     def starts_with(self, prefix: str) -> bool:
#         node = self.root
#         for s in prefix:
#             if s not in node.data:
#                 return False
#             node = node.data[s]
#         return True
