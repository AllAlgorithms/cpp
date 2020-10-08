// Binary Indexed Tree of sum in 2d array
// AbraaoCF - UFCG
#include <bits/stdc++.h>
using namespace std;
#define maxx 1100
int bit[maxx][maxx];
void update(int idx, int idy, int value)
{
	while(idx <= maxx)
  {
		int idy_temp = idy;
		while(idy_temp <= maxx)
    {
			bit[idx][idy_temp] += value;
			idy_temp += (idy_temp &-idy_temp);
		}
		idx += (idx&-idx);
	}
	return;
}
int query(int idx,int idy)
{
	int sum = 0;
	while(idx > 0)
  {
		int idy_temp = idy;
		while(idy_temp > 0)
    {
			sum += bit[idx][idy_temp];
			idy_temp -= (idy_temp &-idy_temp);
		}
		idx -= (idx&-idx);
	}
	return sum;
}
