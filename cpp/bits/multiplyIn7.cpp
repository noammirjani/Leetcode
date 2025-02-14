
/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

// Efficient way to multiply with 7
int multi7(int num){
    return (num << 3) - num; 
    
    // 1 * 7 = 1 * 111 = 111    1000 - 1
    // 2 * 7 = 10 * 111 = 1110  10000 - 10
    // 3 * 7 = 11 * 111 = 10101 11000 - 111
}

int main()
{
    std::cout<<"Hello World" <<"\n";
    
    for (int i = 0; i < 12; i++) std::cout << multi7(i) << "\n";
    return 0;
}