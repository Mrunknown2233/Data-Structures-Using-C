#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


#define LEFT_PAREN -10
#define RIGHT_PAREN -20
#define OPERATOR -30
#define OPERAND -40

#define LEFT_PAREN_PREC 0
#define ADD_PREC 1
#define SUB_PREC 1
#define MUL_PREC 2
#define DIV_PREC 2
#define MOD_PREC 2
#define POW_PREC 3

#define NONE -999

#define MAX 100
#define SS 100
typedef struct
{
	char items[SS];
	int top;
}Stack;
int isEmpty(Stack s)
{
		return s.top==-1;
}
int isFull(Stack s)
{
	return s.top == SS-1;
}
void push(Stack *ps,char sym)
{
	if(isFull(*ps))
		printf("\nStack Overflow");
	else
		ps->items[++ps->top]=sym;
}
char pop(Stack *ps)
{
	if(isEmpty(*ps))
	    {
		printf("\nStack Underflow");
		return 0;
	    }
	else
		return ps->items[ps->top--];
}
char peek(Stack s)
{
	if(isEmpty(s))
	{
		printf("\nNothing to peek !");
		return 0;
	}
	else
		return s.items[s.top];
}

int getType(char symbol)
{
	switch(symbol)
	{
		case '(':
			return LEFT_PAREN;

		case ')':
			return RIGHT_PAREN;

		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			return OPERATOR;

		default:
			return OPERAND;
	}
}


int getPrec(char op)
{
	switch(op)
	{
		case '+':return ADD_PREC;
		case '-':return SUB_PREC;
		case '*':return MUL_PREC;
		case '/':return DIV_PREC;
		case '%':return MOD_PREC;
		case '^':return POW_PREC;
		case '(':return LEFT_PAREN_PREC;

		default:
			return NONE;
	}
}

void infixToPrefix(char infix[],char prefix[])
{
	Stack stack;
	int i,len,type,p,prec;
	char symbol,poppedElement;
	stack.top = -1;
	p=0;
	len=strlen(infix);
	 i=len-1;
	while (i>=0)
	{       symbol=infix[i];
		type=getType(symbol);
		switch(type)
		{

			case RIGHT_PAREN:
				push(&stack,symbol);
				break;
			case LEFT_PAREN:
				while( (poppedElement=pop(&stack))!=')')
					prefix[p++]=poppedElement;

				break;
			case OPERATOR:
				prec=getPrec(symbol);
				while(!isEmpty(stack) && prec<getPrec(peek(stack)))
					prefix[p++]=pop(&stack);
				push(&stack,symbol);
				break;
			case OPERAND:
				prefix[p++]=symbol;
				break;
		}//switch
		i--;
	}//while
	while (!isEmpty(stack))
		prefix[p++] = pop(&stack);

	prefix[p]='\0';
}//function

/*--------------------------------------------------------------------------*/

void main()
{
	char infix[MAX],prefix[MAX];

	int k;
	clrscr();
	printf("\nEnter Infix Expression ");
	gets(infix);

	infixToPrefix(infix,prefix);

	printf("\nPostFix Expression = %s ",strrev(prefix));
   //	k = evaluatePostfix(postfix);
      //	printf("\nValue of PostFix Expression = %d ",k);
getch();
}
