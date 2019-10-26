#include<iostream>

using namespace::std;

void mul(int a[2][2],int b[2][2],int c[2][2])
{
	c[0][0] = a[0][0]*b[0][0] + a[0][1]*b[1][0];
	c[0][1] = a[0][0]*b[0][1] + a[0][1]*b[1][1];
	c[1][0] = a[1][0]*b[0][0] + a[1][1]*b[1][0];
	c[1][1] = a[1][0]*b[0][1] + a[1][1]*b[1][1];
}

void mat_pow(int a[2][2], int n) {
	if(n<2)return ;
	if(n%2==0) {
		int temp[2][2];
		mul(a,a,temp);
		a[0][0]=temp[0][0];
		a[0][1]=temp[0][1];
		a[1][0]=temp[1][0];
		a[1][1]=temp[1][1];
		mat_pow(a,n/2);
	}
	else {
		int temp[2][2],ret[2][2];
		mul(a,a,temp);
		mat_pow(temp,n/2);
		mul(a,temp,ret);
		a[0][0]=ret[0][0];
		a[0][1]=ret[0][1];
		a[1][0]=ret[1][0];
		a[1][1]=ret[1][1];
	}
}

int nth(int n){
int x[2][2]={{1,1},{1,0}};
mat_pow(x,n);
return x[0][0];
}

int main()
{
	int n;
	cin>>n;
	cout<<nth(n)<<endl;
}
