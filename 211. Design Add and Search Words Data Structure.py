class WordDictionary:
    def __init__(self):
        self.trie = {}

    def __str__(self):
        return self.trie.__str__()

    def add(self, word: str) -> None:
        current_node = self.trie
        for letter in word:
            if letter not in current_node:
                current_node[letter] = {}
            current_node = current_node[letter]
        current_node['#'] = True

    def search(self, word: str) -> bool:
        return self._search_recursive(word, self.trie)

    def _search_recursive(self, word: str, current_node) -> bool:
        if not word:
            return '#' in current_node

        letter = word[0]

        if letter == '.':
            for child_char, child_node in current_node.items():
                if child_char != '#' and self._search_recursive(word[1:], child_node):
                    return True
                return False
        else:
            if letter not in current_node:
                return False
            return self._search_recursive(word[1:], current_node[letter])


if __name__ == "__main__":
    x = WordDictionary()
    x.add("bad")
    print(x)
    print(x.search("ba."))
