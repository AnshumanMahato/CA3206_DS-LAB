#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

int size, top = -1;
char *stk;

void push(char);
char pop();
char peek();

int priority(char val)
{
	if (peek() == '\0' || peek() == '(')
		return 1;
	else if (val == '^')
	{
		switch (peek())
		{
		case '^':
			return 0;
		default:
			return 1;
		}
	}
	else if (val == '/' || val == '*')
	{
		switch (peek())
		{
		case '^':
		case '/':
		case '*':
			return 0;
		default:
			return 1;
		}
	}
	else
		return 0;
}

int main()
{
	printf("Enter length of string: ");
	scanf("%d", &size);
	char *exp, *post;
	stk = new char[size + 1];
	exp = new char[size + 1];
	post = new char[size + 1];
	printf("\nEnter infix expression: ");
	scanf("%s", exp);
	int i = 0, len = -1;
	while (exp[i] != '\0')
	{
		if (isalpha(exp[i]))
			post[++len] = exp[i];
		else if (exp[i] == '(')
			push(exp[i]);
		else if (exp[i] == ')')
		{
			while (peek() != '(')
				post[++len] = pop();
			pop();
		}
		else
		{
			while (!priority(exp[i]))
				post[++len] = pop();
			push(exp[i]);
		}
		i++;
	}
	while (top != -1)
	{
		post[++len] = pop();
	}
	post[++len] = pop();
	printf("Post:%s", post);
	return 0;
}

void push(char val)
{
	stk[++top] = val;
}

char pop()
{
	if (top == -1)
		return '\0';
	return stk[top--];
}

char peek()
{
	if (top == -1)
		return '\0';
	return stk[top];
}
