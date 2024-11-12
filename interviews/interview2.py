"""zipRecruiter"""

def ex1():
    # Given a string s, remove all vowels in the string and return the result reversed.
    # "hello" -> "llh"
    # "HELLO" -> "LLH"

    def remove_vowels(string: str) -> str:
        # complexity: run: O(n)  space: O(n)
        vowels = set("aeiou")
        return "".join([s for s in string[::-1] if s.lower() not in vowels])

    print(remove_vowels("hello"))  # llh
    print(remove_vowels("HELLO"))  # LLH


def ex2():
    # Given two lists, songs and animations, where each element is a string formatted as "<name>:<duration>":
    # - <name> represents the name of the song or animation.
    # - <duration> is an integer representing the length in seconds.
    # return for each song, the fittest animation and how many times it can play completely within the song's duration.
    #
    # The fittest animation is defined as:
    #   - An animation whose duration divides the song's duration exactly (no remainder).
    #   - Among all such animations, the one with the fewest repetitions required to fill the song's duration.
    #
    # Example:
    # songs =      ["song1:10", "song2:20", "song3:30"]
    # animations = ["anim1:5", "anim2:10", "anim3:15"]
    # Output=      ["anim2:1", "anim2:2", "anim3:2"]
    # Explanation:
    # - "song1:10" can fit "anim2:10" exactly once.
    # - "song2:20" can fit "anim2:10" exactly twice.
    # - "song3:30" can fit "anim3:15" exactly twice.

    def fittest_animations(songs, animations):
        # complexity: run: O(n*m)  space: O(n+m) where n is the number of songs and m is the number of animations
        songs = [(song.split(":")[0], int(song.split(":")[1])) for song in songs]
        animations = [(anim.split(":")[0], int(anim.split(":")[1])) for anim in animations]

        result = []

        for song_name, song_duration in songs:
            best_animation = None
            best_repetitions = float('inf')  # Initialize to a large number

            # Find the fittest animation
            for anim_name, anim_duration in animations:
                # Check if the animation can fit exactly into the song's duration
                if song_duration % anim_duration == 0:
                    repetitions = song_duration // anim_duration
                    if repetitions < best_repetitions:
                        best_repetitions = repetitions
                        best_animation = anim_name

            # Add the result for the song
            result.append(f"{best_animation}:{best_repetitions}")
        return result

    print(fittest_animations(["song1:10", "song2:20", "song3:30"], ["anim1:5", "anim2:10", "anim3:15"]))
    # ["anim2:1", "anim2:2", "anim3:2"]
    print(fittest_animations(["song1:2", "song2:3", "song3:4"], ["anim1:1", "anim2:2", "anim3:3"]))
    # ["anim2:1, "anim3:1", "anim2:2"]


def ex3():
    # Given a matrix of integers and an integer named `radius`, return the maximum sum of a rhombus-shaped submatrix
    # that can be formed within the matrix, where the rhombus has a side length equal to the given `radius`.

    # A rhombus in this context is defined as a shape whose four sides are of equal length, with the center of the
    # rhombus located at any matrix element, and the shape expanding symmetrically outward in all directions. The
    # radius defines how far from the center the vertices of the rhombus extend.

    # Example:
    # Input Matrix:
    # 1  2  9  4  5  6  7
    # 8  9  9  9  3  4  0
    # 5  6  9  8  9  0  1
    # radius = 2

    # A rhombus with a radius of 2 is formed with the center at (1, 2) (value 9), and the sum of the values within
    # the rhombus is calculated. The rhombus includes the elements in the pattern:
    # 9 + 9 + 9 + 9 + 9 + 9 + 9 + 9 = 72
    def find_maximal_rhombus(mat, radius):
        pass

    matrix = [
        [1, 2, 9, 4, 5],
        [8, 9, 9, 9, 3],
        [5, 6, 9, 8, 9]
    ]
    print(find_maximal_rhombus(matrix, 2))  # 72


def ex4():
    # given array of strings, return the number of pairs of strings (s1,s2) where s1 is the suffix of s2
    # suffix can be the whole string
    # ["ab", "b", "bca", "a", "bab"] -> 4 4 ("b", "ab"), ("b", "bab"), ("ab", "bab"), ("a", "bca")

    def count_suffix_pairs(strings):
        # where n is the number of strings and m is the length of the longest string

        # complexity: run: O(m*n*log(n))  space: O(n*m)
        # revers = sorted([word[::-1] for word in strings]) # reverse: On*m sort: O(n*log(n)) -> O(n*m*log(n))
        # counts = [0] * len(revers)
        # for i in range(1, len(revers)):
        #     counts[i] = counts[i-1] + 1 if revers[i].startswith(revers[i-1]) else counts[i-1]
        # return counts[-1]

        # complexity: run: O(n^2*m)  space: O(n*m)
        # suffix_set = set()
        # count = 0
        # for s in strings:
        #     for suffix in suffix_set:
        #         if s.endswith(suffix):
        #             count += 1
        #         if suffix.endswith(s):
        #             count += 1
        #     suffix_set.add(s)
        # return count

        # complexity: run: O(n*m)  space: O(n*m)
        suffix_trie = {}
        count = 0

        for s in strings:
            curr_trie = suffix_trie
            for char in reversed(s):
                if char not in curr_trie:
                    curr_trie[char] = {}
                curr_trie = curr_trie[char]
            curr_trie["end"] = True

        for s in strings:
            curr_trie = suffix_trie
            for char in reversed(s):
                if "end" in curr_trie:
                    count += 1
                curr_trie = curr_trie[char]
        return count

    print(count_suffix_pairs(["a", "b", "ab", "ba", "aba", "bab"]))
    # 6 ("a", "ba"), ("a", "aba"), ("b", "ab"), ("b", "bab"), ("ab", "bab"), ("ba", "aba")
    print(count_suffix_pairs(["ab", "b", "bca", "a", "bab"]))
    # 4 ("b", "ab"), ("b", "bab"), ("ab", "bab"), ("a", "bca")


if __name__ == "__main__":
    # ex1()
    # ex2()
    ex3()
    # ex4()
