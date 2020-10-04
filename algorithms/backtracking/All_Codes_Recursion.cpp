/*

Problem Statement

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. 
You are given a numeric string S. 
Write a program to return the list of all possible codes that can be generated from the given string.

For Example - 
Input:
1123

Output:
aabc
kbc
alc
aaw
kw

Being a recursive solution, this won't work for large inputs. But we can use DP to make it work for Large results.

*/


#include <iostream>
#include<string.h>
using namespace std;

int getString(string str) {
    int res = 99999;
    if(str.size() == 1) {
    	 int num = str[0] - '0';
         //c = 'a' + (num-1);
         return num-1;
    }
    else if(str.size() > 1) {
        int num = ((str[0] - '0')*10) + (str[1] - '0');
		    if(num > 26) {
         	return res;
        }
        else {
            //c = 'a' + (num-1);
            return num-1;
        }
        
    }
	
    return res;
    
}

int helper(string input, string curString, string modString, string output[10000]) {
   static int i;
    int cs = getString(curString);
  	if(input.empty() && cs < 27) {   
        	modString +=('a' + cs);
          output[i++] = modString;
        	return i;
    }

    if(cs < 27) {
      modString +=('a' + cs);
    }
    
     int count = helper(input.substr(1),input.substr(0,1),modString,output);
     if(input.length() > 1) {
       int check = getString(input.substr(0,2));
       if(check < 27) {
         count = helper(input.substr(2),input.substr(0,2),modString,output);
       }   
     }
     return count;
    }


int getCodes(string input, string output[10000]) {
    return helper(input,"","",output);
}

int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
