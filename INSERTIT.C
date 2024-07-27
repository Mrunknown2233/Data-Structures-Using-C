#include<stdio.h>
#include <conio.h>
#define MAX 1000
void insertition(int x[], int n)
{
	int i,j,numToBeInserted;

	for(i=1;i<n;i++)
	{
		numToBeInserted=x[i];
		for(j=i-1;j>=0 && x[j]>numToBeInserted;j--)
		{
			x[j+1]=x[j];
			x[j]=numToBeInserted;
		}
	}
}

void main()
{
	int i,x[10],n;

	clrscr();
	//accpeting
	printf("\nEnter the no of elements: ");
	scanf("%d",&n);
	printf("\nEnetr the elements one by one ");
	for(i=0;i<n;i++)
		scanf("%d", &x[i]);
	//displaying
	printf("\nUnsorted array ");
	for( i = 0;i<n;i++)
		printf("%d ", x[i]);
       //	calling function
	insertition(x,n);
	//displaying
	printf("\nsorted array ");
	for(i = 0;i<n;i++)
		printf("%d ", x[i]);
getch();
}

