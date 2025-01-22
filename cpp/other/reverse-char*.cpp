#include <iostream>
#include <cstring>

/**

const char* str = "Hello";:
// Points to a read-only area in memory, the string is stored in the data segment, the content of the string cannot be changed but the pointer itself can be changed, i.e., str = "hi"
char str[] = "Hello";:
// The string is copied into an array in the stack memory, the size of the array is determined at compile time based on the length of the string (including the null terminator \0). The content can be changed.

 */

char* reverse(const char* str) {
    if (!str) return nullptr; // Handle null input

    size_t length = strlen(str);
    char* reversed = new char[length + 1];
    
    for (size_t i = 0; i < length; ++i) {
        reversed[i] = str[length - i - 1];
    }
    reversed[length] = '\0'; // Null-terminate the reversed string
    return reversed;
}

void reverse(char* str) {
    if (!str) return; // Handle null input

    size_t length = strlen(str);
    for (size_t i = 0; i < length / 2; ++i) {
        std::swap(str[i], str[length - i - 1]);
    }
}

int main() {
    // Reverse const char* with dynamic allocation
    const char* original = "Hello World";
    char* reversed = reverse(original);
    
    if (reversed) {
        std::cout << "Original: " << original << "\n";
        std::cout << "Reversed: " << reversed << "\n";
        delete[] reversed; // Free the allocated memory
    } else {
        std::cout << "Input string is null.\n";
    }
    
    // Reverse char* in place
    char inplace[] = "Hi there, inplace!";
    reverse(inplace);
    std::cout << "In-place reversed: " << inplace << "\n";

    return 0;
}
