
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>


#define  MAX 100
#define NEG_INF -32768
typedef struct
{
	int items[MAX];
	int top;
} Stack;

int isFull(Stack s)
{
	/*if(s.top == MAX-1)
		return 1;
	return 0;
	      */

	return  s.top == MAX-1 ? 1 : 0;
}
int isEmpty(Stack s){ return s.top == -1 ? 1:0;}


void show (Stack s)
{
	int i;
	if(isEmpty(s))
	{
		printf("\nYour enetered numbered is not having any integer part");
		return;
	}
	for(i=s.top;i>=0;i--)
	{     //  y[i++] = s.items[i];
		printf("%d",s.items[i]);
	}
}

int push (Stack *ps, int element)
{
	if(isFull(*ps))
		return 0;
	ps->items[++ps->top]=element;
	return 1;

}
int pop (Stack *ps)
{
	if(isEmpty(*ps))
		return NEG_INF;
	return ps->items[ps->top--];
}
int peek(Stack s)
{
	int i;
	if(isEmpty(s))
		return NEG_INF;
	return s.items[s.top];
}
void main()
{
	int choice,element,res;
	Stack s;
	clrscr();
	s.top = -1;//Very Imp step

	while(1)
	{
		printf("\n--------Menu-------");
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Show\n5.Exit\nEnter your choice : ");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1:
				printf("\nEnter the element :");
				scanf("%d",&element);

				res = push(&s,element);
				if(res)
					printf("\nElement pushed !");
				else
					printf("\StackOverflow");
				break;
			case 2:
				res = pop(&s);
				if(res==NEG_INF)
					printf("\nStackUnderFlow");
				else
					printf("\nPopped element : %d",res);
				break;
			case 3:
				res = peek(s);
				if(res==NEG_INF)
					printf("\nStackUnderFlow, nothing to peek");
				else
					printf("\nTopmost element : %d",res);
				break;
			case 4:
				show(s);
				break;
			case 5:
				exit(1);
				break;
		}//switch's end
	}//end of while loop
getch();
}//end of main