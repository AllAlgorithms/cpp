#include <iostream>

using namespace std;

//Print All Subsequences Of String
void printAllSubsequences(string &input, int i, string t){
    // i  to keep track of string indexes
    if(i == input.length()){
        cout<<t<<endl;
        return;
    }

    //For element select it in out subsequence once and leave it out once
    printAllSubsequences(input, i+1, t+input[i]);
    printAllSubsequences(input, i+1, t);

}



int main(){
    string input;
    cout<<"Enter the string of which you want to find subsequences"<<endl;
    cin >> input;

    cout<<"Subsequences of string are: "<<endl;
    printAllSubsequences(input, 0, "");

}


