#include <iostream>
using namespace std;

bool checkPangram(string s) {
    int arr[26] = {0};
    for(int i = 0;i < s.length();i++) {
        if (s[i]!=' ') {
            arr[(int)s[i] - 97] = 1;
        }
    }
    for (int i = 0;i < 26;i++) 
        if (arr[i]==0) 
            return false;
    return true;
}

int main()
{
    string s = "The quick brown fox jumps over the lazy dog";
    if (checkPangram(s)) 
        cout << "Given string is Pangram";
    else 
        cout << "Given string is not Pangram";
    return 0;
}
