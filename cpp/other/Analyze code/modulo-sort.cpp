//Analyze the following code:
const int ARRAY_SIZE = 10;

void func(int array[ARRAY_SIZE]) {
    int p = 0;
    for (int r = 0; r < 4; r++) {
        for (int i = p; i < ARRAY_SIZE; i++) {
            if (array[i] % 5 == r) {
                if (i != p) {
                    int temp = array[p];
                    array[p] = array[i];
                    array[i] = temp;
                }
                p++;
            }
        }
    }
}

#include <algorithm>

template <typename T, size_t N>
void sortArrayByRemainder(T array[N], int modulo = 5) {
    int position = 0;
    for (int remainder = 0; remainder < modulo; remainder++) {
        for (int i = position; i < N; i++) {
            if (array[i] % modulo == remainder) {
                if (i != position) {
                    std::swap(array[position], array[i]);
                }
                position++;
            }
        }
    }
}


// Counting sort approach - O(n + modulo) time complexity
template <typename T, size_t N>
void countingSortByRemainder(T array[N], int modulo = 5) {
    vector<vector<T>> count(modulo);

    for(const T& num : array) {
        count[num % modulo].push_back(num);
    }

    for (int r = 0, p = 0; r < modulo; r++) {
        for (const T& num : count[r]) {
            array[p++] = num;
        }
    }
}



/*
Questions:
What does this code do?
How would you improve the code (without considering performance)?
*/

// Answer:
/*
This code sorts an array of integers based on the remainder of the elements when divided by 5. The array is sorted such that all elements with a remainder of 0 are placed at the beginning, followed by elements with a remainder of 1, 2, 3, and 4.

1 4 7 0 10 3 6 9 2 5
After sorting:
0 10 5 1 6 7 2 3 4 9

- better  function name such as sortArrayByRemainder
- better variable name, r->remainder, p->position
- use std::swap instead of manual swapping
- use variable for the modulo value (5) instead of hardcoding, and first loop will iterate from 0 to modulo-1 value
- can be templated to work with any array type and size

current complexity time is O(n*modulo) and space is O(1)
after improvement, time complexity is O(n*modulo) and space is O(1)

performance can be improved by using a counting sort approach, which would reduce the time complexity to O(n + modulo) at the cost of additional space complexity.
*/
