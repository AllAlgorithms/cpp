//Fibonacci Sum
//https://www.spoj.com/problems/FIBOSUM/
//This question wants the user to calculate Fibonacci with in a range. A naive approach will be to simply use the
//relation F(N) = F(N - 1) + F(N - 2) to find the nth fibonacci and the itterate over the range. A better approach will be to derrive
//a recurence relation of the fibonacci series. Refer this link for mathematics behind it https://www.youtube.com/watch?v=WT_TGxQrV1k&t=214s
//Even now itterating to find the sum for fibbonaci will give us TLE because of large constraints.
//So there's an observation to get TLE fixed. 1, 1, 2, 3, 5, 8, 13, 21, 34. The observation is Sum till Nth fibonacci is F(n+2) - 1
//This observation is true throughout. Now calculating sum within range from n to m will be sum till m minus sum till n

#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
#define mat(x, y, name) vector< vector<lli> > name (x, vector<lli>(y));

lli MOD = 1000000007;

vector< vector<lli> > matMul(vector< vector<lli> > A, vector< vector<lli> > B)
{
    vector< vector<lli> > C(A.size(), vector<lli>(B[0].size()));
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B[0].size(); j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < B.size(); k++)
                C[i][j] = (C[i][j] + ((A[i][k] * B[k][j]) % MOD)) % MOD;
        }
    }
    return C;
}

vector< vector<lli> > matPow(vector< vector<lli> > A, int p)
{
    if (p == 1)
        return A;
    if (p&1)
        return matMul(A, matPow(A, p-1));
    else
    {
        vector< vector<lli> > C = matPow(A, p/2);
        return matMul(C, C);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mat(2, 1, F);
    mat(2, 2, T);
    T[0][0] = 0;
    T[0][1] = 1;
    T[1][0] = 1;
    T[1][1] = 1;
    F[0][0] = 1;
    F[1][0] = 1;
    int t;
    cin >> t;
    while(t--)
    {
        lli n, m;
        cin >> n >> m;
        lli minSum = (n == 0) ? 0 : ((matMul(matPow(T, n), F)[0][0]) - 1) % MOD;
        lli maxSum = (m == 0) ? 0 : ((matMul(matPow(T, m+1), F)[0][0]) - 1) % MOD;
        lli ans = (maxSum - minSum) % MOD;
        if (ans < 0)
        {
            ans += MOD;
            ans = ans % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
