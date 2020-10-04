#include <stdio.h>
int common=0;
void swap (int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
	return;
}

int partition(int *a,int start,int end)
{
	int i=0;
	int pivot_index=0;
	int pivot=a[end];
	if (start==end)
	return pivot_index;

	for (i=0;i<end;i++)
	{
		if (a[i]<pivot)
		{
			swap(&a[i],&a[pivot_index]);
			pivot_index++;
		}
	}
	int temp=pivot_index;
		for (i=0;i<end;i++)
	{
		if (a[i]==pivot)
		{
			swap(&a[i],&a[pivot_index]);
			pivot_index++;
		}
	}
	common=pivot_index-temp;
	swap(&a[pivot_index],&a[end]);
	return pivot_index;
}

void quicksort (int * a, int start,int end)
{
	if (start>=end)
	return;

	int pivot=partition(a,start,end);
	int temp=common;
	common=0;
	quicksort(a,start,pivot-temp-1);
	quicksort(a,pivot+1,end);
}

void print(int *a,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
		if(i==n-1)
		printf(". \n");
		else printf(", ");
	}
}

int main(void)
{
	int i=0;
	printf("Please enter the size of array:\n");
	int n;
	scanf("%d",&n);
	int a[n];
	printf("Please enter the elements of array:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	print(a,n);
	quicksort(a,0,n-1);
	print(a,n);

  return 0;
}
