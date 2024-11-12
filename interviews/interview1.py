"""Amazon"""


def ex1():
    """Lexicographically Smallest Symmetric Rearrangement

    palindrome/ symmetric is a string that is the same as its reverse
    Given a string that is symmetrical, rearrange the characters such that:
    The rearranged string is symmetric.
    The rearranged string is lexicographically the smallest possible
    """
    def compute_encoded_name(name_string):
        mid = len(name_string) // 2
        half_str = "".join(sorted(name_string[:mid]))

        # Create the encoded name
        if len(name_string) % 2 != 0:
            res = half_str + name_string[mid] + half_str[::-1]
        else:
            res = half_str + half_str[::-1]
        return res

    # Test cases
    print(compute_encoded_name("ac"))


def ex2():
    """Special Anagram

    special anagram - a pair of dna is special if they are anagrams of each other after any number of occurrences
    of at most one character from each  dna sequence.
    """
    def is_special_anagram_2(dna1, dna2):
        # with python function - Counter, shorter and more readable
        from collections import Counter
        count1 = Counter(dna1)
        count2 = Counter(dna2)

        # Find the difference between the counts of the two strings
        diff1 = count1 - count2  # letters extra in dna1
        diff2 = count2 - count1

        return len(diff1) <= 1 and len(diff2) <= 1

    def is_special_anagram_1(dna1, dna2):
        count_dna1, count_dna2 = {}, {}

        # count the number of occurrences of each character in the dna sequences
        for i in dna1:
            count_dna1[i] = count_dna1.get(i, 0) + 1
        for i in dna2:
            count_dna2[i] = count_dna2.get(i, 0) + 1

        # find the difference between the counts of the two strings
        diff_dna1 = {}
        for key, value in count_dna1.items():
            if key not in count_dna2:
                diff_dna1[key] = value
            elif count_dna2[key] < value:
                diff_dna1[key] = value - count_dna2[key]

        diff_dna2 = {}
        for key, value in count_dna2.items():
            if key not in count_dna1:
                diff_dna2[key] = value
            elif count_dna1[key] < value:
                diff_dna2[key] = value - count_dna1[key]

        # check if the difference is at most 1
        return len(diff_dna1) <= 1 and len(diff_dna2) <= 1

    def get_sequence(dna):
        result = []
        for pair in dna:
            # if is_special_anagram_1(pair[0], pair[1]):
            if is_special_anagram_2(pair[0], pair[1]):
                result.append("YES")
            else:
                result.append("NO")
        return result

    dna_pairs = [["abcee", "acdeedb"], ["safddadfs", "famafmss"], ['sljffsaje', 'sljsje']]
    print(get_sequence(dna_pairs))


if __name__ == "__main__":
    ex1()
    ex2()
