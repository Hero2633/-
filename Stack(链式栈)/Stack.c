#include"Stack.h"
//初始化栈
void InitStack(ST* ps)
{
	assert(ps);
	ps->Head = NULL;
	ps->size = 0;
}
//销毁栈
void DestroyStack(ST* ps)
{
	assert(ps);
	struct SListode* cur = ps->Head;
	while (cur)
	{
		struct SListode* next = cur->next;
		free(cur);
		cur = next;
	}
	ps->Head = NULL;
	ps->size = 0;
}
//创建节点,程序自动创建，用户无需关心
static struct SListode* BuyListNode(DataType x)
{
	struct SListode* NewNode = (struct SListode*)malloc(sizeof(struct SListode));
	if (NewNode == NULL)
	{
		printf("malloc fail!\n");
		exit(EXIT_FAILURE);
	}
	NewNode->next = NULL;
	NewNode->val = x;
	return NewNode;
}
//入栈
void StackPush(ST* ps, DataType x)
{
	assert(ps);
	struct SListode* NewNode = BuyListNode(x);
	struct SListode* next = ps->Head;
	NewNode->next = next;
	ps->Head = NewNode;
	ps->size++;
}
//出栈
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	struct SListode* next = ps->Head->next;
	free(ps->Head);
	ps->size--;
	ps->Head = next;
}
//判断栈是否为NULL
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->size == 0;
}
//统计栈里元素个数
size_t StackSize(ST* ps)
{
	assert(ps);
	return ps->size;
}
//获取栈顶元素
DataType StackTop(ST* ps)
{
	assert(ps);
	assert(StackEmpty(ps)==false);
	return ps->Head->val;
}