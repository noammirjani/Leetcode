import random


def shuffle_generator():
    numbers = [i for i in range(1, 101)]  # 1 to 100

    for i in range(99, 0, -1):  # Fisher-Yates Shuffle
        j = random.randint(0, i)
        numbers[i], numbers[j] = numbers[j], numbers[i]
        yield numbers[i]
    yield numbers[0]


# use the generator
gen = shuffle_generator()

for _ in range(100):  # 1 to 100 shuffled
    print(next(gen))


# fisher-yates shuffle:
# i starts from the last index and goes till 1
# j is a random number between 0 and i
# swap the numbers[i] with numbers[j]
# yield the numbers[i]
# next time, i will be 1 less while the used number will be the last number meaning it will not be used again
# finally yield the first number as it will be the last number left
# this way, we can shuffle the numbers
# time - O(n) space - O(N) due to the numbers list (if it is given as input, then space - O1)
