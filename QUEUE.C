#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define NEG_INF -32768
#define MAX 5
typedef struct
{
	int items[MAX];
	int front,rear;
}Queue;

int isEmpty(Queue q) { return q.rear<q.front; }

int isFull(Queue q) {  return q.rear==MAX-1; }

int insert(Queue *pq,int element)
{
	if(isFull(*pq))
		return 0;
	pq->items[++(pq->rear)]=element;
	return 1;
}
int poll(Queue *pq) //poll means remove or delete.Poll is used in Queue
{
	int temp;
	if(isEmpty(*pq))
		return NEG_INF;
	/* here we have used NEG_INF because the element to be inserted could
		be a 0 or a 1 so while returning the values if we had used
		return 0 or return 1 here we wouldn't know that if this 0 or
		1is coming as the polled element or it is coming from because
		the Queue is empty
	*/
	temp=pq->items[(pq->front)++];
	//(pq->front)++;
	/**
	    *Note:
		>  This function ensures that after all the elements in the
		   Queue is polled out the front and rear are sent back to their
		   respective positions 0 and -1 respectively.
		>  Due to this we can add(insert)any new element(s) in the
		   queue.
		>  If this is not done it will show that the queue is overflowed.
	*/
	if(isEmpty(*pq))
	{
		pq->rear = -1;
		pq->front = 0;
	}
	return temp;
}
int peek(Queue q)
{
	if(isEmpty(q))
		return NEG_INF;
	return q.items[q.front];
}
void show(Queue q)
{
	int i;
	if(isEmpty(q))
		printf("\nNothing to show the queue is empty ");

	else
	{
		printf("\nQueue Elements : ");
		for(i=q.front;i<=q.rear;i++)
			printf("%d ",q.items[i]);
	}
}

void main()
{
	int choice,element,a;
	Queue queue;
	clrscr();
	//very imp
	queue.rear=-1;
	queue.front=0;

	while(1)
	{
		printf("\n-----------Menu----------");
		printf("\n1.Insert\n2.Pop\n3.Peek\n4.Show\n5.Exit");
		printf("\nEnter your choice ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the element: ");
				scanf("%d",&element);
				if(element == NEG_INF)
					printf("\nIllegal Element to insert");

				else
				{
				       a=(insert(&queue,element));
						switch(a)
						      {
							case 1:
								printf("\nElement  inserted ");
								break;
							case 0 :
								printf("\n Queue Overflow");
								break;
							}

				}
				break;
			case 2:
				element=poll(&queue);
				if(element==NEG_INF)
					printf("\nQueue underflow");
				else
					printf("\nPolled element = %d",element);

				break;

			case 3:
				element =peek(queue);
				if(element==NEG_INF)
					printf("\nNothing to peek");
				else
					printf("\nPeeked  element = %d",element);

			      break;
			case 4:
				show(queue);
				break;

			case 5:
				exit(1);
			default:
				printf("\nOOPS! U HAVE ENTERED THE WRONG CHOICE\nTRY AGAIN :) ");
		}//switch's braces
	}//while's braces
}//end of main



