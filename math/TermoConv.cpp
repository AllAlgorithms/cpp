#include <iostream>
using namespace std;

int main()
{
    float x;
    // Convert temperature from Celsius to Fahrenheit, Reamur, and Kelvin
    cout << "Temperature in Celsius   = ";
    cin >> x;

    float f,r,k;
    f=1.8*x+32;
    r=0.8*x;
    k=273+x;

    cout << "Temperature in Fahrenheit= " << f << endl;
    cout << "Temperature in Reamur    = " << r << endl;
    cout << "Temperature in Kelvin    = " << k << endl;

    system("pause");
    return 0;
}