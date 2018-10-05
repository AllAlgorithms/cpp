#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) (ll)(a).size()

typedef long long ll;
typedef pair<ll,ll> pii;

const ll lt=100005;
ll mod=1000000007;

int main()
{
	cout << "Enter a number (<1000000) to get all prime numbers less than that numbers ";
	ll n;
	cin >> n;
	ll arr[n+1] = {0};
	ll i, j;
	for(i = 2 ; i <= n ; i ++)
		for(j = 2 * i ; j <=n ; j += i)
			arr[j] = 1;

	for(i = 2 ; i <= n ; i ++)
		if(arr[i] == 0)
			cout << i << " ";
	cout << endl;
	return 0;
}