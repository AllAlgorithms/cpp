#include <iostream>
using namespace std;

int main()
{
    int x,y,z,a=0;
    // This program will check if a number is a prime number
    cout << "Number= ";
    cin >> x;

    for(y=2;y<=(x/2);y++)
    {
        z=x%y;
        if(z==0)
        {
            a=a+1;
        }
    }
    if(a==0)
    {
        cout << "A prime number" << endl;
    }
    else
    {
        cout << "Not a prime number" << endl;
    }

    system("pause");
    return 0;
}