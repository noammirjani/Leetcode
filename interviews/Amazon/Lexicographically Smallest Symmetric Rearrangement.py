# palindrome/ symmetric is a string that is the same as its reverse
# Given a string that is symmetrical, rearrange the characters such that:
# The rearranged string is symmetric.
# The rearranged string is lexicographically the smallest possible


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
if __name__ == "__main__":
    print(compute_encoded_name("ac"))
