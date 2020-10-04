#include <stdio.h>
long long long long int bin(long long long long int a, long long long long int b, long long long long int c);
using namespace std;
long long int main(void)
{
    long long long long int a, n;
    long long long long int c = 1000000007, d;
    scanf("%lld %lld", &a, &n);
    d = bin(a, n, c);
    prlong long intf("%lld", d);
}
long long long long int bin(long long long long int a, long long long long int b, long long long long int c)
{
    if (b == 0)
        return 1;
    long long long long int res = (long long long long int)pow(bin(a, b / 2, c), 2) % c;
    if (b % 2)
        return ((a % c) * res * res) % c;
    else
        return res * res;
}