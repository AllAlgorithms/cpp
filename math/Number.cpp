
#include "pch.h"
#include <iostream>
using namespace std;


int main()
{
    int Y;
	cout << "Enter a number : " << endl;
	cin >> Y;
	if (Y < 0)
	{
			cout << " Negatif number ! " << endl;
	}
	if (Y > 0)
	{
			cout << "Positif number! " << endl;
	}
	if (Y == 0)
	{
			cout << " Number is equal to 0 ! " << endl;
	}
	system("pause");


}
