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
// 双向链表销毁
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
// 双向链表打印
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
// 双向链表尾插
void ListPushBack(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	/*ListNode* NewNode = ListCreate(x);
	ListNode* tail = pHead->prev;
	tail->next = NewNode;
	NewNode->prev = tail;
	pHead->prev = NewNode;
	NewNode->next = pHead;*/
	ListInsert(pHead,x);//函数复用
}
// 双向链表尾删
void ListPopBack(ListNode* pHead)
{
	assert(pHead);
	assert(!is_Empty(pHead));//判空
	/*ListNode* tail = pHead->prev;
	ListNode* prev = tail->prev;
	ListNode* next = pHead;
	free(tail);
	prev->next = next;
	next->prev = prev;*/
	ListErase(pHead->prev);//函数复用
}
// 双向链表头插
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
	ListInsert(pHead->next,x);//函数复用
}
// 双向链表头删
void ListPopFront(ListNode* pHead)
{
	assert(pHead);
	assert(!is_Empty(pHead));//判空
	/*ListNode* prev = pHead;
	ListNode* cur = pHead->next;
	ListNode* next = cur->next;
	free(cur);
	prev->next = next;
	next->prev = prev;*/
	ListErase(pHead->next);//函数复用
}
// 双向链表查找
ListNode* ListFind(ListNode* pHead, LTDataType x)
{
	assert(pHead);
	assert(!is_Empty(pHead));//表都为NULL了，就没办法找了
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
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);//pos不能为NULL,由于参数限制我们无法对pos判断是否为哨兵位头节点，因此我们假设pos传的都是合法指针和NULL
	ListNode* NewNode = ListCreate(x);
	ListNode* prev = pos->prev;
	NewNode->next = pos;
	pos->prev = NewNode;
	prev->next = NewNode;
	NewNode->prev = prev;
}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);//由于参数限制，我们无法判断表是否为NULL；
	ListNode* prev = pos->prev;
	ListNode* next = pos->next;
	free(pos);
	prev->next = next;
	next->prev = prev;
}
//判断链表是否为NULL
bool is_Empty(ListNode* pHead)
{
	assert(pHead);
	return pHead == pHead->prev;
}