#include <iostream>
using namespace std;

int main()
{
    float a,b=0,c=0;
    //This program will count the average of all the data, type "0" to show the average.
    while(a!=0)
    {
        b=b+1;
        cout << "Data " << b << "= ";
        cin >> a;
        c=c+a;
    }

    float average=c/(b-1);
    cout << " \n";
    cout << "Average= " << average << endl;

    system("pause");
    return 0;
}