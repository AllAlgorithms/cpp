#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int x,y,z=0;
    // This program will check if a number is a prime number
    cout << "Number= ";
    cin >> x;

    for(y=2;y<=sqrt(x);y++)
    {
        if(x%y==0)
        {
            z=++z;
        }
    }
    if(z==0)
    {
        cout << "A prime number" << endl;
    }
    else
    {
        cout << "Not a prime number" << endl;
    }

    return 0;
}
