#include <bits/stdc++.h>
#define blue ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;


void golombSequence(int n)
{
	int dp[n + 1];
	dp[1] = 1;
	cout << dp[1] << " ";
	for (int i = 2; i <= n; i++)
	{
		dp[i] = 1 + dp[i - dp[dp[i - 1]]];
		cout << dp[i] << " ";
	}
}

int main()
{
    blue;
	int n = 10;
	golombSequence(n);
	return 0;
}
