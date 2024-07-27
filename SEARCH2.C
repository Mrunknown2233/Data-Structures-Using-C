#include<stdio.h>
#include <conio.h>
void select (int x[],int n)
{
	int i,j,temp;
	int small,index;

		      for(i=0;i<n-1;i++)
		      {
			small = x[i];
			index=i;
			for(j=i+1 n;j<n-1;j++)
			{
			   if(x[j] < small)
				{
					small=x[j];
					index=j;
				}
			}
			x[index]=x[i];
			x[i]=small;

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
	select(x,n);
	//displaying
	printf("\nsorted array ");
	for(i = 0;i<n;i++)
		printf("%d ", x[i]);
getch();
}
