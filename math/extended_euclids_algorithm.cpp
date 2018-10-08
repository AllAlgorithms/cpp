#include <bits/stdc++.h>

using namespace std;

int gcdExtended(int a, int b, int& x, int& y)
{
    if (a == 0)
    {
        x = 0;
        y = 1;
        return b;
    }

    int xTemp, yTemp;
    int gcd = gcdExtended(b%a, a, xTemp, yTemp);

    x = yTemp - (b / a) * xTemp;
    y = xTemp;

    return gcd;
}

int main()
{
    int x, y, a, b;
    cin >> a >> b;
    int gcd = gcdExtended(a, b, x, y);
    
    cout << "Found (x, y) = (" << x << ", " << y << ") pair satisfying the equation:" << endl;
    cout << a << "x + " << b << "y = gcd(" << a << ", " << b << ")" << endl;

    return 0;
}
