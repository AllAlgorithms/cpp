//Favourite Dice
//https://www.spoj.com/problems/FAVDICE/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        double n;
        cin >> n;
        double ans = 0;
        for (int i = 1; i <= n; i++) ans += (double)1/i;
        ans *= n;
        cout << ans << endl;
    }
    return 0;
}
