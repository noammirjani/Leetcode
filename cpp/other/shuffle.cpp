/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

//Shuffle the elements in the array such that no two elements are in same place.
void shuffle(std::vector<int>& arr) {
    int last = arr[0];
    
    for (int i = 1; i < arr.size(); i++) {
        std::swap(arr[i], last);
    }
    
    arr[0] = last; 
}

// Fisher-Yates shuffle algorithm
// time complexity: O(n)
// space complexity: O(1)
// each element in index i will be swapped with a random element in the range [0, i] 
void shuffle(std::vector<int>& arr) {
    srand(time(0));
    
    for (int i = arr.size(); i >0; i--) {
        int j = rand() % i;
        std::swap(arr[i-1], arr[j]);
    }
}

// 1 2 3 4 
//   1 1 1
// 2   2 2
// 3 3   3
// 4 4 4

// 4 3 2 1
// 4 1 3 2

int main()
{
    std::vector<int> arr  {1,2,3,4,5};
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";
    shuffle(arr);
    std::cout << "\n";
    for (int i = 0; i < arr.size(); i++)
        std::cout << arr[i] << " ";

    return 0;
}