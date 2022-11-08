#include"Stack.h"
void test1()
{
	ST st;
	InitStack(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st,4);
	StackPush(&st, 5);
	StackPop(&st);
	StackPush(&st, 6);
	StackPush(&st, 7);
	StackPush(&st, 8);
	StackPush(&st, 9);
	StackPush(&st, 10);
	int top = StackTop(&st);
	size_t len = StackSize(&st);
	printf("%d\n",top);
	DestroyStack(&st);
}
int main()
{
	test1();
	return 0;
}