#ifndef __MY_STACK
#define __MY_STACK

struct MyStack
{
	int top;
	int *arr;
	int capacity;

	MyStack(int cap)
	{
		top = -1;
		capacity = cap;
		arr = new int[cap];
	}

	void push(int c)
	{
		arr[++top] = c;

	}

	int pop()
	{
		return arr[top--];
	}

	bool isEmpty()
	{
		return top==-1;
	}

	int getTop()
	{
		return arr[top];
	}
};

#endif
