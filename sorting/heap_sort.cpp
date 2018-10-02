#include <iostream> 
  
using namespace std; 

void heapify(int input[], int n, int i) 
{ 

    int largest = i; // Assign the largest as root
    int left = 2*i + 1;  // Calculate the index of left element
    int right = 2*i + 2; // Calculate the index of right element
  
    //Checking if the left is larger than current large value
    if (left < n && input[left] > input[largest]) 
        largest = left; 
    
    //Checking if the right is larger than current large value
    if (right < n && input[right] > input[largest]) 
        largest = right; 
        
    if (largest != i) 
    { 
        swap(input[i], input[largest]); 
  
        heapify(input, n, largest); 
    } 
} 
  
void heapSort(int input[], int n) 
{   // Function to perform heap sort. 

    // Building the heap, effectively rearranging the array.
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(input, n, i); 

    for (int i=n-1; i>=0; i--) 
    { 
        swap(input[0], input[i]); 
        heapify(input, i, 0); 
    } 
}

int main() 
{   
    int n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    int array[n];
    cout<<"Enter the elements of array"<<endl;
    
    for(int i=0; i<n; i++){
        cin>>array[i];
    }
    heapSort(array, n); 
    cout << "Sorted array is \n"; 
    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return 1;
}
