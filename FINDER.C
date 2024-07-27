#include<stdio.h>
#include <conio.h>
void finder ( int x[], int n,int key,int *cnt,int index[],int *j)
{
	int i,k;
	for(i=0;i<n;i++)
	{
		if(key==x[i])
		{       index[k]=i;
			k++;
			(*cnt)++;
		}
	}
	*j=k;


}
void main()
{
	int i,j,x[100],n,cnt,key,index[100];
	cnt =0;
	j = 0;
	clrscr();
	//accpeting
	printf("\nEnter the no of elements: ");
	scanf("%d",&n);
	printf("\nEnter the elements one by one ");
	for(i=0;i<n;i++)
		scanf("%d", &x[i]);
	printf("\nEnter the key u want to be searched : ");
	scanf("%d",&key);
	//displaying
       /*	printf("\nYour array ");
	for( i = 0;i<n;i++)
		printf("%d ", x[i]);
		*/
	finder(x,n,key,&cnt,index,&j);

       if(cnt>0)
       {
		printf("\nThe key(%d) is repeated %d times",key,cnt);
		printf("\nThe key was repeated at index : ");
		for(i=0;i<j;i++)
			printf("%d,",index[i]);
       }
       else
		printf("\nThe key is not found");




getch();
}
