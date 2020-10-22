#include<iostream>
#define eps 1e-3
using namespace std;



int binary_search_float(double a[],int lo,int hi,double key)
{
    double res=-1;
    while(hi>=lo)
    {
        int m = lo + (hi-lo) / 2;
        if(a[m]-key >= eps){
            hi = m-1;
        }else if(abs(a[m]-key) <= eps){
            res =m;
            break;
        }else{
            lo = m+1;
        }
    }
    return res;
}


int main(){
    int n;
    double key;
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter array elements: ";
    double a[n];

    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    cout << "Enter search key: ";
    cin>>key;

    double res = binary_search(a, 0, n-1, key);

    if(res > -1)
        cout<< key << " found at index " << res << endl;
    else
        cout << key << " not found" << endl;
    return 0;
}