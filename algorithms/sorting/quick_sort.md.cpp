//
// C++ implementation of merge sort
//
// The All ▲lgorithms Project
//
// 
// https://github.com/allalgorithms/cpp
//
// Contributed by: MOHAMMAD SHAHANSHA
// Github: @mdshahansha (mdshahansha44411@gmail.com)
//
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// Merge the two half into a sorted data.

int patition(int input[],int s,int e){
    if(s>=e){
        return 0;
    }
    int count=0;
    for(int i=1+s;i<=e;i++)
    {
    if(input[s]>=input[i])
    {
    	    count++;
    }
      int   c=s+count;
        
        }
    
    int temp=input[s];
    input[s]=input[s+count];
    input[s+count]=temp;
    
    int i=0,j=e;
    while(i<s+count && j>s+count)
    {
        if(input[i]<=input[s+count]){
            i++;
        }
        else if(input[j]>input[s+count]){
            j--;
        }
        else
        {
            int temp=input[i];
    		input[i]=input[j];
            input[j]=temp;
            i++;
            j--;
        }
            
    }
    return s+count;
    }

void qs(int input[],int s,int e){
    if(s>=e){
        return;
    }
    int c=patition(input,s,e);
    qs(input,s,c-1);
    qs(input,c+1,e);
}
void quickSort(int input[], int size) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Change in the given array itself.
     Taking input and printing output is handled automatically.
  */
int s=0,e=size-1;
    if(s>=e){
        return;
    }
  qs(input,s,e);
 		   
}



int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}



    
    
