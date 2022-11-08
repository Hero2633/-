#include"Stack.h"
void test1()
{
	ST st;
	InitStack(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st,5);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);
	StackPop(&st);

	//int top = StackTop(&st);
	size_t ret = StackSize(&st);
	printf(" %zu",ret);
	DestroyStack(&st);
}
int main()
{
	test1();
	return 0;
}