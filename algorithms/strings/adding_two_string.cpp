/*
Program : To add 2 string

this Program is Contributed by github@b419007
*/

#include <iostream> 
using namespace std; 

int Len(string &str1, string &str2) 
{ 
    int len1 = str1.size(); 
    int len2 = str2.size(); 
    if (len1 < len2) 
    { 
        for (int i = 0 ; i < len2 - len1 ; i++) 
            str1 = '0' + str1; 
        return len2; 
    } 
    else if (len1 > len2) 
    { 
        for (int i = 0 ; i < len1 - len2 ; i++) 
            str2 = '0' + str2; 
    } 
    return len1; 
}

string add( string a, string b ) 
{ 
    string result; 
    int len = Len(a, b); 
  
    int carry = 0;
    for (int i = len-1 ; i >= 0 ; i--) 
    { 
        int aBit = a.at(i) - '0'; 
        int bBit = b.at(i) - '0'; 
        int sum = (aBit ^ bBit ^ carry)+'0'; 
  
        result = (char)sum + result; 
        carry = (aBit & bBit) | (bBit & carry) | (aBit & carry); 
    } 

    if (carry) 
        result = '1' + result; 
  
    return result; 
} 

int main() 
{ 
    string str1,str2;
    cout<<"Enter the string 1 :";
    cin>>str1;
    cout<<"Enter the string 2 :";
    cin>>str2;
    cout << "Sum is " << add(str1, str2); 
    return 0; 
} 
