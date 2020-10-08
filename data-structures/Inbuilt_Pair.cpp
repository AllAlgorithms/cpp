/*
Pair is a container class in CPP defined in <utility> header file. It consists of two elements.

You can access the first element as 'first' and second element as 'second'. They both can be of any data type. (This class is made using templates)

We can use the pair class where we need to store two properties like when finding diameter of a binary tree.

This is the inbuilt version, we can create our own version too.

*/
#include<bits/stdc++.h>
using namespace std;

int main() {
	
	pair <int, char> p ; 
  
    p.first = 100; 
    p.second = 'G' ; 
  
    cout << p.first << " " ; 
    cout << p.second << endl ; 
  
    return 0; 
	
}


