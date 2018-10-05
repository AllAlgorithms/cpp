#include<iostream>
using namespace std;
int count[1111111]={0};
void countsort(int arr[],int size){
    int A[size]={0};
    for(int i=0;i<size;i++)
        count[arr[i]]++;
    int j=0;
    for(int i=0;i<1111111;i++){
        int temp = count[i];
        while(temp--){
            A[j++] = i;
        }
    }
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
}
int main(){
    int size;
    cin>>size;
    int arr[size];
    for(int i=0;i<size;i++)
        cin>>arr[i];
    cout<<endl<<"Entered array is : ";
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
       countsort(arr,size-1);
}