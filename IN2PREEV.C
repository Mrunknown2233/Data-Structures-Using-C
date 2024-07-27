
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


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
	{
		printf("\nstack underflow");
		return 0;
	}
	return ps->items[ps->top--];
}
int evaluatePrefix(char expression[])
{
	Stack stack;
	int len,i;
	int num1,num2,num,rev;
	stack.top=-1;

	len=strlen(expression);

	for(i=len-1;i>=0;i--)
	{
		/*Checks if the current element is space or not
		if it is spcae then it continues the loop for next iteration
		without checking other conditions
		*/
		if(isspace(expression[i]))
			continue;
		else if(isdigit(expression[i]))
		{
			num=0;
			 /*it is a possiblitiy that the string entered
			   contains a value with multiple digits,but
			   the above expression will only work for a digit
			   so it goes and checks whether the adjacent
			   character is a digit being a part of the previous one
			  */
			while(isdigit(expression[i]))
			{
				num = num*10 + (expression[i]-'0');
				/*The statement above coverts the character
				  into a numeric value.
				*/
				i--;
				rev=0;
	 while(num!=0)
	 {
		rev= rev *10 +(num%10);
		num/=10;
	 }
			}
			push(&stack,rev);
			i++; //settlement for 'for' loop;
			/*it is done because the i is decremented above
			which messes up the value of i and after the while
			loop suppose there is an operator to it wont be counted
			as the i would have been decremented by 1 for the change
			in 'for' loop
			*/
		}

		else //when the character is an operator
		{
			num1=pop(&stack);
			num2=pop(&stack);

			switch(expression[i])
			{
				case '+':
					push(&stack,num1+num2);
					break;
				case '-':
					push(&stack,num1-num2);
					break;
				case '*':
					push(&stack,num1*num2);
					break;
				case '/':
					if(num2==0)
					{
						printf("\nCannot divide by 0" );
						exit(2);
					}
					push(&stack,num1/num2);

					break;
				default:
					printf("\nIllegal argument !");
					exit(1);
			}//end of switch
		}//end of else
	}//end of for loop
	return pop(&stack);
}

void main()
{
	char expression[MAX];
	 int res,rev;
	 clrscr();
	 printf("\nEnter prefix expression");
	 gets(expression);
	 res=evaluatePrefix(expression);

	 printf("\nResult = %d",res);
getch();
}