#include<iostream.h>	//to add input and output stream
#include<conio.h>	//to add console based functions

void main()
{
	int i,j,n,fact,sign=-1;
	float x, p,sum=0;
	cout<<"\nEnter the value of x : ";
	cin>>x; //values of sine series
	cout<<"\nEnter the value of n : ";
	cin>>n;  //number of terms required in sine series

	for(i=1;i<=n;i+=2)
	{
		p=1;
		fact=1;
		for(j=1;j<=i;j++)
		{
			p=p*x;
			fact=fact*j;
		}
		sign=-1*sign;
		sum+=sign*p/fact;
	}
	cout<<"\nsin "<<x<<"= "<<sum; //output of the sine series upto n term


	getch();
}