#include <iostream>
using namespace std;


int main()
{
    int n;
    cin >> n;

    long long cat[100000];
    cat[0] = 1;
    cout << cat[0];

    for (int i = 1; i <= n; i++)
    {
        cat[i] = 0;
        for (int j = 0; j < i; j++)
            cat[i] += cat[j] * cat[i - j - 1];
        cout << cat[i] << endl;
    }
}
