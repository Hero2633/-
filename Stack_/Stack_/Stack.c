#include"Stack.h"
//初始化栈
void InitStack(ST* ps)
{
	assert(ps);//防止乱传
	ps->capcity = 0;
	ps->top = 0;
	ps->nums = NULL;
}
//销毁栈
void DestroyStack(ST*ps)
{
	assert(ps);
	ps->capcity = 0;
	ps->top = 0;
	free(ps->nums);
}
//检查扩容，不提供给用户，由程序自己完成
static void Check_Capcity(ST* ps)
{
	assert(ps);
	if (ps->capcity == ps->top)//需要扩容
	{
		int len = (ps->capcity == 0) ? 4 : ps->capcity * 2;
		DataType* tmp = (DataType*)realloc(ps->nums,len*sizeof(DataType));
		if (!tmp)
		{
			printf("realloc fail!\n");
			exit(EXIT_FAILURE);
		}
		ps->nums = tmp;
		ps->capcity = len;
	}
}
//入栈
void StackPush(ST* ps,DataType x)
{
	assert(ps);
	Check_Capcity(ps);
	ps->nums[ps->top] = x;
	ps->top++;
}
//出栈
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//判空
	ps->top--;
}
//判断栈是否为NULL
bool StackEmpty(ST* ps)
{
	assert(ps);
	return !ps->top;
}
//统计栈的元素
size_t StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
//获取栈顶元素
DataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//栈不为空，我们才有元素获取;
	return ps->nums[ps->top - 1];
}