#include<bits/stdc++.h>
using namespace std;

void add()
{
    int n, sum = 0, i, number;
    cout << "How many numbers you want to add: ";
    cin >> n;
    cout << "Please enter the number one by one: \n";
    for (i = 1; i <= n; i++)
    {
        cin >> number;
        sum = sum + number;
    }
    cout << "\n Sum of the numbers = " << sum;
}
void sub()
{
    int num1, num2, z;
    cout << " \n Enter the First number = ";
    cin >> num1;
    cout << "\n Enter the Second number = ";
    cin >> num2;
    z = num1 - num2;
    cout << "\n Subtraction of the number = " << z;
}
void multi()
{
    int num1, num2, mul;
    cout << " \n Enter the First number = ";
    cin >> num1;
    cout << "\n Enter the Second number = ";
    cin >> num2;
    mul = num1 * num2;
    cout << "\n Multiplication of two numbers = " << mul;
}
void division()
{
    int num1, num2, div = 0;
    cout << " \n Enter the First number = ";
    cin >> num1;
    cout << "\n Enter the Second number = ";
    cin >> num2;
    while (num2 == 0)
    {
        cout << "\n Divisor canot be zero"
                "\n Please enter the divisor once again: ";
        cin >> num2;
    }
    div = num1 / num2;
    cout << "\n Division of two numbers = " << div;
}
void sqr()
{
    int num1;
    float sq;
    cout << " \n Enter a number to find the Square: ";
    cin >> num1;
    sq = num1 * num1;
    cout << " \n Square of " << num1 << " is : " << sq;
}
void srt()
{
    float q;
    int num1;
    cout << "\n Enter the number to find the Square Root:";
    cin >> num1;
    q = sqrt(num1);
    cout << " \n Square Root of " << num1 << " is : " << q;
}
void mode()
{
    int num1, num2, remi;
    cout << " \n Enter the First number = ";
    cin >> num1;
    cout << "\n Enter the Second number = ";
    cin >> num2;
  
   remi=num1%num2; 
    cout << "\n Remainder of two numbers = " << remi;
}


void prime()
{
  int num, i, chk=0;
    cout<<"Enter a Number: ";
    cin>>num;
    for(i=2; i<num; i++)
    {
        if(num%i==0)
        {
            chk++;
            break;
        }
    }
    if(chk==0)
        cout<<"\nIt is a Prime Number";
    else
        cout<<"\nIt is not a Prime Number";
}

int main()
{
    
    int opr;

    do
    {
        cout << "Select any operation from the C++ Calculator"
                "\n1 = Addition"
                "\n2 = Subtraction"
                "\n3 = Multiplication"
                "\n4 = Division"
                "\n5 = Square"
                "\n6 = Square Root"
                "\n7 = Modulo"
                "\n8 = Prime"
                "\n9 = Exit"
                "\n \n Make a choice: ";
        cin >> opr;

        switch (opr)
        {
        case 1:
            add(); 
            break;
        case 2:
            sub(); 
            break;
        case 3:
            multi(); 
            break;
        case 4:
            division(); 
            break;
        case 5:
            sqr(); 
            break;
        case 6:
            srt();
            break;
        case 7:
            mode(); 
            break;
        case 8:
            prime();
            break;
        case 9:
            exit(0); 
            break;
        default:
            cout << "Something is wrong..!!";
            break;
        }
        cout << " \n------------------------------\n";
    } while (opr != 7);
 
 return 0;
}

