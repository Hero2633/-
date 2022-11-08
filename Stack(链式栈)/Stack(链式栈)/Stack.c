#include"Stack.h"
//��ʼ��ջ
void InitStack(ST* ps)
{
	assert(ps);
	ps->Head = NULL;
	ps->size = 0;
}
//����ջ
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
//�����ڵ�,�����Զ��������û��������
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
//��ջ
void StackPush(ST* ps, DataType x)
{
	assert(ps);
	struct SListode* NewNode = BuyListNode(x);
	struct SListode* next = ps->Head;
	NewNode->next = next;
	ps->Head = NewNode;
	ps->size++;
}
//��ջ
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	struct SListode* next = ps->Head->next;
	free(ps->Head);
	ps->size--;
	ps->Head = next;
}
//�ж�ջ�Ƿ�ΪNULL
bool StackEmpty(ST* ps)
{
	assert(ps);
	return ps->size == 0;
}
//ͳ��ջ��Ԫ�ظ���
size_t StackSize(ST* ps)
{
	assert(ps);
	return ps->size;
}
//��ȡջ��Ԫ��
DataType StackTop(ST* ps)
{
	assert(ps);
	assert(StackEmpty(ps)==false);
	return ps->Head->val;
}