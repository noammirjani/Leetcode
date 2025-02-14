'''
Given a string consisting of 'w' (representing workdays) and 'h' (representing general holidays), along with an integer
 indicating the number of workdays that can be converted into holidays (days off), return the length of the longest
  consecutive holiday period that can be achieved.

example: whwwhhw, 2 -> result will be: 5
'''


# time complexity - ON space complexity O1
def longest_consecutive(calendar, num_day_off):
    max_len = 0
    left = 0
    used_off = 0
    for right in range(len(calendar)):
        if calendar[right] == 'w':
            used_off += 1
        while used_off > num_day_off:
            if calendar[left] == 'w':
                used_off -= 1
            left += 1
        max_len = max(max_len, right - left + 1)
    return max_len


# brute force - time complexity On^2, space O1
def longest_consecutive_3(calender, num_day_off):
    max_len = 0
    for left in range(len(calender)):
        day_off_copy = num_day_off
        for right in range(left, len(calender)):
            if calender[right] == 'w':
                day_off_copy -= 1
            if day_off_copy == 0:
                max_len = max(max_len, right-left+1)
    return max_len


def longest_consecutive_2(calender, num_day_off):
    current = 0
    max_len = 0
    left = 0
    used_off = 0

    for i, day in enumerate(calender):
        if day == 'h':
            current += 1
        elif day == 'w':
            while left <= i and used_off == num_day_off:
                if calender[left] == 'w':
                    used_off -= 1
                current -= 1
                left += 1
            current += 1
            used_off += 1
        max_len = max(max_len, current)
    return max_len


if __name__ == "__main__":
    print(longest_consecutive("whwwhhw", 2))   # -> 5
    print(longest_consecutive("whwwhhw", 1))   # -> 3
    print(longest_consecutive("whwwhhw", 0))   # -> 2


