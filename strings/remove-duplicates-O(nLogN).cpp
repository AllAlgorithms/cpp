// CPP program to remove duplicate character 
// from character array and print in sorted 
// order 
#include <bits/stdc++.h> 
using namespace std; 
  
char *removeDuplicate(char str[], int n) 
{ 
    // create a set using string characters 
    // excluding '\0' 
    set<char>s (str, str+n-1); 
  
    // print content of the set 
    int i = 0; 
    for (auto x : s) 
       str[i++] = x; 
    str[i] = '\0'; 
  
    return str; 
} 
  
// Driver code 
int main() 
{ 
   char str[]= ""; //Enter string here 
   int n = sizeof(str) / sizeof(str[0]); 
   cout << removeDuplicate(str, n); 
   return 0; 
}