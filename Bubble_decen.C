#include <stdio.h>
#include <conio.h>
void bubble( int x[] , int n)
{
	int i,j,temp;
	int cnt = 0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1;j++)
		{
			if(x[j]>x[j+1])
			{
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;
			}
		cnt++;
		}
	}
	printf("count = %d",cnt);
}
void main()
{
	int x[10],n;
	int i,j,temp,lock;
	int cnt = 0;

	clrscr();
	//accpeting
	printf("\nEnter the no of elements: ");
	scanf("%d",&n);
	printf("\nEnetr the elements one by one ");
	for( i = 0;i<n;i++)
		scanf("%d", &x[i]);
	//displaying
	printf("\nUnsorted array ");
	for( i = 0;i<n;i++)
		printf("%d ", x[i]);
       //	calling function
	bubble(x,n);
       /*
	{
	for(i= 0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(x[j]>x[j+1])
			{
				temp = x[j];
				x[j] = x[j+1];
				x[j+1] = temp;

			}
		cnt++;
		}
	}
	printf("count = %d",cnt);
}        */
	//displaying
	printf("\nsorted array ");
	for(i = 0;i<n;i++)
		printf("%d ", x[i]);
getch();
}
