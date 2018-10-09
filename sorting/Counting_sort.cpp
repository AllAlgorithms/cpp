// CPP Program for counting sort 
#include <iostream> 
#include <string.h> 
#define RANGE 255 
using namespace std;
  
// function that sorts the given string in alphabatical order 
string countSort(string arr) 
{ 
    // The output character array that will have sorted arr
    char output[arr.size()]; 
  
    // Create a count array to store count of inidividul characters
    int count[RANGE + 1], i; 
    memset(count, 0, sizeof(count)); 
  
    // Store count of each character
    for(i = 0; i<arr.size(); ++i) 
        ++count[arr[i]]; 
  
    // Change count[i] so that count[i] now contains actual 
    // position of this character in output array 
    for (i = 1; i <= RANGE; ++i) 
        count[i] += count[i-1]; 
  
    // output character array 
    for (i = 0; i<arr.size(); ++i) 
    { 
        output[count[arr[i]]-1] = arr[i]; 
        --count[arr[i]]; 
    } 
  
    // Copy the output array to arr 
    for (i = 0; i<arr.size(); ++i)
        arr[i] = output[i];
    
    return arr;
} 
  
// Driver program
int main() 
{ 
    string arr = "geeksforgeeks";
    cout<<"Unsorted characters: "<<arr<<"\n";

    string output = countSort(arr);
    cout<<"Sorted characters: "<<output<<"\n";
    return 0; 
} 