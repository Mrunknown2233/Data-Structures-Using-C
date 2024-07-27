
#include <stdio.h>
# include <conio.h>
#define  max 100
void heapup (int heap[],int newnode )
{
	int parentIndex, temp;

	 if(newnode>0)
	 {
		parentIndex=(newnode-1)/2;
		if(heap[parentIndex]<heap[newnode])
		{
			temp = heap[parentIndex];
			heap[parentIndex] = heap[newnode];
			heap[newnode]=temp;
			heapup(heap,parentIndex);
		}
	 }
}


void heapdown(int heap[],int root,int lastIndex)
{
	int leftChild,rightChild,largeIndex,temp;
	leftChild= root*2 +1;
	rightChild = root*2 + 2; // it can also be returned as rightChild = leftChild + 1;
	if(leftChild<=lastIndex)
	{
		//left child exits
		if(rightChild<=lastIndex)
		{
			//both the child exits
			if(heap[leftChild]> heap[rightChild])
				largeIndex = leftChild;
			else
				largeIndex= rightChild;
		}
		else
		{       //only left child exits
			largeIndex = leftChild;
		}
		if(heap[root]<heap[largeIndex])
		{
			//swaps the heap[root] and heap [largeChild]
			temp = heap[root];
			heap[root] = heap[largeIndex];
			heap[largeIndex] = temp;
			// calling the heapdown function again
			heapdown(heap,largeIndex,lastIndex);
		}
	}//left child doesn't exits
}//function ka braces
void heapsort(int x[],int n)
{
	int i,temp;
	//for making the heap tree
	for(i=1;i<n;i++)
		heapup (x,i);
	//for sorting the heap tree with heapdown function
	for(i=n-1;i>0;i--)
	{
		temp=x[0];
		x[0]=x[i];
		x[i]=temp;
		heapdown(x,0,i-1);
	}
}
void main( )
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
	heapsort(x,n);
	//displaying
	printf("\nsorted array ");
	for(i = 0;i<n;i++)
		printf("%d ", x[i]);
       getch();

}

