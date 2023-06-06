#include <iostream>
#include "array.h"

// Main function that accepts command line arguments
int main(int argc, char** argv) {
    Array<int> *arr = new Array<int>();
    
    std::cout << arr;

    delete arr;
    
    return 0;
}