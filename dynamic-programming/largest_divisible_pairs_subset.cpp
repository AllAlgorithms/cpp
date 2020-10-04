#include <bits/stdc++.h>
#define blue ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int largestSubset(int a[], int n)
{
	sort(a, a + n);
	int dp[n];
	dp[n - 1] = 1;

	for (int i = n - 2; i >= 0; i--)
    {
		int mxm = 0;
		for (int j = i + 1; j < n; j++)
			if (a[j] % a[i] == 0)
				mxm = max(mxm, dp[j]);

		dp[i] = 1 + mxm;
	}

	return *max_element(dp, dp + n);
}

int main()
{
    blue;
	int a[] = { 21, 4, 6, 13, 11, 2 };
	int n = sizeof(a) / sizeof(a[0]);
	cout << largestSubset(a, n) << endl;
	return 0;
}
