#include <iostream>
#include <string>

using namespace std;

int	main()
{
	string roman;
	int	number;
	int	c;

	std::cout << "Enter a number from 1 to 3999 to converte it to Roman numeral: ";
	std::cin >> number;

	if ((number >= 4000) || (number < 0))
		cout << endl << "~INVALID NUMBER~" << endl;
	else
	{
		if(number >= 1000)
		{
			c = number/1000;
			for (int i = 0; i < c; i++)
				roman += 'M';
			number %= 1000;
		}
		if (number >= 100)
		{
			c = number/100;
			if ( c == 9)
				roman += "CM";
			else if (c >= 5)
			{
				roman += 'D';
				for (int i = 0; i < c - 5; i++)
					roman += 'C';
			}
			else if (c == 4)
				roman += "CD";
			else if (c >= 1)
			{
				for (int i = 0; i < c ; i++)
					roman += 'C';
			}
			number %= 100;
		}
		if (number >= 10)
		{
			c = number/10;
			if ( c == 9)
				roman += "XC";
			else if (c >= 5)
			{
				roman += 'L';
				for (int i = 0; i < c - 5; i++)
					roman += 'X';
			}
			else if (c == 4)
				roman += "XL";
			else if (c >= 1)
			{
				for (int i = 0; i < c ; i++)
					roman += 'X';
			}
			number %= 10;
		}
		if (number >= 1)
		{
			if ( c == 9)
				roman += "IX";
			else if (c >= 5)
			{
				roman += 'V';
				for (int i = 0; i < c - 5; i++)
					roman += 'I';
			}
			else if (c == 4)
				roman += "IV";
			else if (c >= 1)
			{
				for (int i = 0; i < c ; i++)
					roman += 'I';
			}
		}
	}
	cout << "Roman Numeral: " << roman << endl;

	return (0);
}
