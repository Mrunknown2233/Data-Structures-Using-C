#include<stdio.h>
#include <conio.h>
void select (int x[],int n)
{
	int i,j,temp;
	int large,index;

		      for(i=n-1;i>0;i--)
		      {
			large = x[0];
			index=0;
			for(j=0;j<=i;j++)
			{
			   if(x[j]> large)
				{
					large=x[j];
					index=j;
				}
			}

			x[index]=x[i];
			x[i]=large;


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
