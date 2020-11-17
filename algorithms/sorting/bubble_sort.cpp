// C++ implementation of Bubble Sort(Optimised Solution).
//
// The All ▲lgorithms Project
//
// https://allalgorithms.com/
// https://github.com/allalgorithms/cpp
//
// Contributed by: Abhishek Jaiswal
// Github: @Abhishek-iiit
//
// Refactoring by: Cigan Oliviu David
// Github: @CiganOliviu
//

#include <iostream>


unsigned int readLength() {

    unsigned int length;

    std::cin >> length;

    return length;
}

void readArray(int array[], unsigned int length) {

    for (int i = 0; i < length; i++)
        std::cin >> array[i];
}


void bubbleSortArray(int array[], unsigned int length)  {

    bool changed;

    length -= 1;

    for (int i = 0; i < length; i++) { 

        changed = false; 

        for (int j = 0; j < length - i; j++) { 

            if (array[j] > array[j + 1]) {
 
                std::swap(array[j], array[j+1]);            
                changed = true; 
            } 
        } 

        if (changed == false)
            return;
    } 
}

void outputArray(int array[], unsigned int length) {

    for (int i = 0; i < length; i++)
        std::cout << array[i] << " ";

    std::cout << '\n';
}

int main() {  
    
    std::cout << "Input the total size : ";
    
    unsigned int length;
    
    length = readLength();

    int array[length];
    
    std::cout << "Input the number one-by-one : ";

    readArray(array, length);

    bubbleSortArray(array, length);
    
    std::cout << "Sorted array:" << std::endl;
    
    outputArray(array, length);

    return 0;
}