
#include "pch.h"
#include <iostream>
using namespace std;


int main()
{
	int FirstNumber, SecondNumber,Result;
	char Calculator;
debut:
	cout << "Enter the first number : " << endl;
	cin >> FirstNumber;
	cout << "Enter + for addition,- for substraction,* to multiply and / to divide" << endl;
	cin >> Calculator;
	cout << "Enter the seconde number : " << endl;
	cin >> SecondNumber;
	switch(Calculator)
	{
	case '+' :
		Result = FirstNumber + SecondNumber;
		cout << "The result is : " << Result << endl;
		system("pause");
		break;
	case '-' :
		Result = FirstNumber - SecondNumber;
		cout << "The result is : " << Result << endl;
		system("pause");

		break;
	case '*' :
		Result = FirstNumber * SecondNumber;
		cout << "The result is : " << Result << endl;
		system("pause");

		break;
	case '/' :
		Result = FirstNumber / SecondNumber;
		cout << "The result is : " << Result << endl;
		system("pause");

		break;
	default :
		goto debut;
		break;

	}

}
