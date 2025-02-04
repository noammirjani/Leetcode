// what the funaction does and Find the Bug in the Following Code:
/* 
function solution(n) {
    let d = new Array(30), l = 0;
    while (n > 0) {
        d[l] = = Math.floor(n / 2)2;
        n = Math.floor(n / 2);let      l += 1;
    }
    for (let p = 1; p < l + 1; ++p) {
     let ok = true;
        for (let i = 0; i < l - p; ++i) {
            if (d[i] != d[i + p]) {
                ok = false;
                break;
            }
        }
        if (ok) return p;
    }
    return -1;
}
/*

bugs:
- bad syntax, defining a function in c++ is not like in javascript, it should be like this:
    int solution(n){}
- bad syntax, using let as defining variables in js instead of using type of variable in c++
n -int, d - int[30], l - int, p - int, ok - bool, i - int
- bad syntax - using == instead of = for assignment, it should be like this:
    d[l] = Math.floor(n / 2)2;
- using Math.floor instead of floor with cmath library
- multiple declaration of l in the while loop

summary:
Syntax errors and incorrect operations in the JavaScript code.
Incorrect logic for converting n to binary.

Explanation
The function solution(n) is trying to find the smallest period p such that the binary representation of n is periodic with period p. This means that the binary digits repeat every p positions.


*/

#include <iostream>
#include <vector>

int solution(int n) {
    if (n == 0) return 1; // Handle the case where n is 0

    std::vector<int> d;
    while (n > 0) {
        d.push_back(n % 2);
        n = n / 2;
    }
    int l = d.size();
    for (int p = 1; p <= l; ++p) {
        bool ok = true;
        for (int i = 0; i < l - p; ++i) {
            if (d[i] != d[
                 + p]) {
                ok = false;
                break;
            }
        }
        if (ok) return p;
    }
    return -1;
}

int main() {
    int n = 21;  // Binary representation: 10101 (period 2)
    int period = solution(n);
    std::cout << "The smallest period for " << n << " is: " << period << std::endl;

    int n = 85;  // Binary representation: 1010101 (period 2  )
    int period = solution(n);
    std::cout << "The smallest period for " << n << " is: " << period << std::endl;
    return 0;
}

// Time complexity: O(log n)^2 (due to the nested loops)
// Space complexity: O(log n) (for the vector storing the binary representation of n)
/*

1010101 = 85

p=1 -> 1 != 0
p=2 -> (0)1 == 2(1), (1)0 == 3(0), (2)1 == 4(1), (3)0 == 5(0), (4)1 == 6(1)
return 2

each 2 bits are repeating in the binary representation of 85
10 10 10 1

*/