#include <stdio.h>
#include <conio.h>
#define MAX 1000
//this function sort the array or the sub array.
void merge (int x[], int lb1, int ub1, int ub2)
{
	int i,j,k,temp[MAX];
	i=lb1;
	j=ub1+1;
	k=0;

	//when both files have data

	while(i<=ub1 && j<=ub2)
	{
		if(x[i] < x[j])
		{
			/*
			temp[k]=x[i];
			i++;k++;
			*/
			temp[k++]=x[i++];
		}
		else
			temp[k++]=x[j++];
	}

	//when only file 1 has data so we copy all elements to temp's array
	while(i<=ub1)
		temp[k++]=x[i++];

	//when only file 2 has data so we copy all elements to temp's array
	while(j<=ub2)
		temp[k++]=x[j++];

	//copy elements from temp's array to original array
	for(i=lb1,k=0;i<=ub2;i++,k++)
		x[i]=temp[k];

}
void mergeSort(int x[],int lb,int ub)
{
	int mid;
	if(lb<ub)
	{
		mid= (lb+ub)/2;
		mergeSort(x,lb,mid);//for the left side of the array
		mergeSort(x,mid+1,ub);//for the right side of the array
		merge(x,lb,mid,ub);
	}
}
void main()
{
	int i,x[MAX],n;

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
	mergeSort(x,0,n-1);
	//displaying
	printf("\nsorted array ");
	for(i = 0;i<n;i++)
		printf("%d ", x[i]);
getch();
}
