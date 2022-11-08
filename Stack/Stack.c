#include"Stack.h"
//��ʼ��ջ
void InitStack(ST* ps)
{
	assert(ps);//��ֹ�Ҵ�
	ps->capcity = 0;
	ps->top = 0;
	ps->nums = NULL;
}
//����ջ
void DestroyStack(ST*ps)
{
	assert(ps);
	ps->capcity = 0;
	ps->top = 0;
	free(ps->nums);
}
//������ݣ����ṩ���û����ɳ����Լ����
static void Check_Capcity(ST* ps)
{
	assert(ps);
	if (ps->capcity == ps->top)//��Ҫ����
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
//��ջ
void StackPush(ST* ps,DataType x)
{
	assert(ps);
	Check_Capcity(ps);
	ps->nums[ps->top] = x;
	ps->top++;
}
//��ջ
void StackPop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//�п�
	ps->top--;
}
//�ж�ջ�Ƿ�ΪNULL
bool StackEmpty(ST* ps)
{
	assert(ps);
	return !ps->top;
}
//ͳ��ջ��Ԫ��
size_t StackSize(ST* ps)
{
	assert(ps);
	return ps->top;
}
//��ȡջ��Ԫ��
DataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));//ջ��Ϊ�գ����ǲ���Ԫ�ػ�ȡ;
	return ps->nums[ps->top - 1];
}