#include"DList.h"
ListNode* ListCreate(LTDataType x)
{
	ListNode* NewNode = (ListNode*)malloc(sizeof(ListNode));
	if (!NewNode)
		exit(-1);
	NewNode->val = x;
	NewNode->prev = NULL;
	NewNode->next = NULL;
	return NewNode;
}
void InitDummyHead(ListNode* pHead)
{
	assert(pHead);
	pHead->prev = pHead;
	pHead->next = pHead;
}
// ˫����������
void ListDestory(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	ListNode* next = NULL;
	while (cur!=pHead)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	free(cur);
}
// ˫�������ӡ
void ListPrint(ListNode* pHead)
{
	assert(pHead);
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		printf("%d->",cur->val);
		cur = next;
	}
	printf("NULL\n");
}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	/*ListNode* NewNode = ListCreate(x);
	ListNode* tail = pHead->prev;
	tail->next = NewNode;
	NewNode->prev = tail;
	pHead->prev = NewNode;
	NewNode->next = pHead;*/
	ListInsert(pHead,x);//��������
}
// ˫������βɾ
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(!is_Empty(pHead));//�п�
	/*ListNode* tail = pHead->prev;
	ListNode* prev = tail->prev;
	ListNode* next = pHead;
	free(tail);
	prev->next = next;
	next->prev = prev;*/
	ListErase(pHead->prev);//��������
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	/*ListNode* prev = pHead;
	ListNode* cur = pHead->next;
	ListNode* NewNode = ListCreate(x);
	prev->next = NewNode;
	NewNode->prev = prev;
	NewNode->next = cur;
	cur->prev = NewNode;*/
	ListInsert(pHead->next,x);//��������
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(!is_Empty(pHead));//�п�
	/*ListNode* prev = pHead;
	ListNode* cur = pHead->next;
	ListNode* next = cur->next;
	free(cur);
	prev->next = next;
	next->prev = prev;*/
	ListErase(pHead->next);//��������
}
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	assert(!is_Empty(pHead));//��ΪNULL�ˣ���û�취����
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->val == x)
			return cur;
		else
			cur = cur->next;
	}
	return NULL;
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);//pos����ΪNULL,���ڲ������������޷���pos�ж��Ƿ�Ϊ�ڱ�λͷ�ڵ㣬������Ǽ���pos���Ķ��ǺϷ�ָ���NULL
	ListNode* NewNode = ListCreate(x);
	ListNode* prev = pos->prev;
	NewNode->next = pos;
	pos->prev = NewNode;
	prev->next = NewNode;
	NewNode->prev = prev;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	assert(pos);//���ڲ������ƣ������޷��жϱ��Ƿ�ΪNULL��
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}
//�ж������Ƿ�ΪNULL
bool is_Empty(ListNode* pHead)
{
	assert(pHead);
	return pHead == pHead->prev;
}