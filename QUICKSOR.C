#include <stdio.h>
#include <conio.h>
#define max 1000
int partition(int x[], int lb,int ub)
{
	int up,down,pivot,temp;
	pivot=x[lb];
	up=ub;
	down=lb;


		while(down<up)
		{
			while(x[down]<=pivot && down<ub)
				down++;
			while(x[up]>pivot)
				up--;
			if(down<up)
			{       //swaping x[down] with x[up]
				temp = x[down];
				x[down]=x[up];
				x[up]=temp;
			}
		 }



	//swaping the pivot with up jo index pr hai vo no ke sath
		x[lb]=x[up];
		x[up]=pivot;
	return up ;


}


void quick (int x[], int lb, int ub)
{
	int j;

	if(lb>=ub)
		return;


	j= partition(x,lb,ub);
	quick(x,lb,j-1);//for left partition
	quick(x,j+1,ub);//for right partition
}
void main()
{
	int i,x[max],n;

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
	quick(x,0,n-1);
	//displaying
	printf("\nsorted array ");
	for(i = 0;i<n;i++)
		printf("%d ", x[i]);
getch();
}
