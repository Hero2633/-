#define  _CRT_SECURE_NO_WARNINGS 0
#include"SList.h"
// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	if (!tmp)
		exit(-1);
	tmp->val = x;
	tmp->next = NULL;
	return tmp;
}

// �������ӡ
void SListPrint(const SListNode* plist)
{
	const SListNode* cur = plist;
	while (cur)
	{
		printf("%d->",cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

// �����������
void SListDestroy(SListNode* plist)
{
	SListNode* cur = plist;
	SListNode* next = NULL;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
}
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* cur = *pplist;
	SListNode* NewNode = BuySListNode(x);
	if (cur)
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		cur->next = NewNode;
	}
	else
	{
		*pplist = NewNode;
	}
}

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* cur = *pplist;
	SListNode* NewNode = BuySListNode(x);
	NewNode->next = cur;
	*pplist = NewNode;
}

// �������βɾ
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);//����ΪNULL�Ͳ�Ҫ��ɾ����
	SListNode* cur = *pplist;
	SListNode* prev = NULL;
	if (!cur->next)//ֻ��һ���ڵ���Ҫ��������
	{
		free(cur);
		*pplist = NULL;
	}
	else
	{
		while (cur->next)
		{
			prev = cur;
			cur = cur->next;
		}
		free(cur);
		prev->next = NULL;
	}
}

// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	SListNode* cur = *pplist;
	assert(cur);//����ΪNULL�Ͳ���ɾ����
	*pplist = cur->next;
	free(cur);
}
// ���������
SListNode* SListFind(const SListNode* plist, SLTDateType x)
{
	assert(plist);//����Ϊ�վͲ�������
	const SListNode* cur = plist;
	while (cur)
	{
		if (cur->val == x)
			break;
		else
			cur = cur->next;
	}
	return (SListNode*)cur;
}

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿����̫�٣��������ǵ����������޷�֪��pos��ǰһ���ڵ㣬���޷����½ڵ���pos�ڵ��posǰһ���ڵ�֮����������
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);//NULLָ��ɲ���������һ������;
	SListNode* next = pos->next;
	SListNode* NewNode = BuySListNode(x);
	pos->next = NewNode;
	NewNode->next = next;
}

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�����̫��
void SListEraseAfter(SListNode* pos)
{
	assert(pos);//��Ҫ��NULLָ�����;
	assert(pos->next);//���pos��β�ڵ㣬��û������ɾ
	SListNode* Next = pos->next->next;
	free(pos->next);
	pos->next = Next;
}