#define  _CRT_SECURE_NO_WARNINGS 0
#include"SList.h"
// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* tmp = (SListNode*)malloc(sizeof(SListNode));
	if (!tmp)
		exit(-1);
	tmp->val = x;
	tmp->next = NULL;
	return tmp;
}

// 单链表打印
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

// 单链表的销毁
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
// 单链表尾插
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

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert(pplist);
	SListNode* cur = *pplist;
	SListNode* NewNode = BuySListNode(x);
	NewNode->next = cur;
	*pplist = NewNode;
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
	assert(pplist);
	assert(*pplist);//链表为NULL就不要在删除了
	SListNode* cur = *pplist;
	SListNode* prev = NULL;
	if (!cur->next)//只有一个节点需要单独处理
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

// 单链表头删
void SListPopFront(SListNode** pplist)
{
	assert(pplist);
	SListNode* cur = *pplist;
	assert(cur);//链表为NULL就不再删除了
	*pplist = cur->next;
	free(cur);
}
// 单链表查找
SListNode* SListFind(const SListNode* plist, SLTDateType x)
{
	assert(plist);//链表为空就不在找了
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

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？参数太少，由于这是单链表，我们无法知道pos的前一个节点，就无法将新节点在pos节点和pos前一个节点之间链接起来
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	assert(pos);//NULL指针可不能链接下一个数据;
	SListNode* next = pos->next;
	SListNode* NewNode = BuySListNode(x);
	pos->next = NewNode;
	NewNode->next = next;
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？参数太少
void SListEraseAfter(SListNode* pos)
{
	assert(pos);//不要对NULL指针操作;
	assert(pos->next);//如果pos是尾节点，就没东西可删
	SListNode* Next = pos->next->next;
	free(pos->next);
	pos->next = Next;
}