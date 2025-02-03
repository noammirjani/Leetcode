#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Given a number, the task is to convert it into a zigzag number.
// 1956 -> 1695 . 195 -> 159 . 12345 -> 15243
// complexity: time O(logn), space O(logn) Log base 10 of n cause we are converting number to digits
int zigzag(int number) {
    vector<int> digits;
    
    int temp = number;
    while (temp > 0) {
        digits.insert(digits.begin(), temp % 10);  
        temp /= 10;
    }
     
    int ret = 0, left = 0, right = digits.size() - 1;
    while (left <= right) {
        ret = ret * 10 + digits[left++];
         if (left <= right) ret = ret * 10 + digits[right--];
    }
    
    return ret; 
}

//complexity: time O(logn), space O(1)
int zigzag2(int number) {
    int ret = 0, numOfDigits = log10(number) + 1;
    int leftDivisor = pow(10, numOfDigits - 1), rightDivisor = 1;

    while (leftDivisor >= rightDivisor) {
        int left = (number / leftDivisor) % 10;
        ret = ret * 10 + left;
        leftDivisor /= 10;

        if (leftDivisor >= rightDivisor) {
            int right = (number / rightDivisor) % 10;
            ret = ret * 10 + right;
            rightDivisor *= 10;
        }
    }
    return ret;
}


int main()
{
    int number = 1956; 
    std::cout << number << "\n" << zigzag(number);  //1695

    return 0;
}