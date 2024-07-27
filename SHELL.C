#include <stdio.h>
#include <conio.h>
void ShellSort(int x[], int n)
{
	int i,j,incr,num;
	incr = n/2;
	while(incr>=1)
	{
		for(i=incr;i<n;i++)
		{
			num=x[i];
			for(j=i-incr;j>=0 && num<x[j];j-=incr)
			{
				x[j+incr] = x[j];
				x[j] = num;
			}
		}
	incr/=2;
	}
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
	ShellSort(x,n);
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
