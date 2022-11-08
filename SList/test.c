#define  _CRT_SECURE_NO_WARNINGS 0
#include"SList.h"
void test1()
{
	/*SListNode* Node = NULL;
	Node=BuySListNode(1);
	Node=BuySListNode(2);
	Node=BuySListNode(3);
	SListPrint(Node);
	SListDestroy(Node);*/
	SListNode* head = NULL;
	/*SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head,3);*/
	SListPushFront(&head, 3);
	SListPushFront(&head, 2);
	SListPushFront(&head,1);
	SListPrint(head);
	SListPopBack(&head);
	SListPrint(head);
	SListPopBack(&head);
	SListPrint(head);
	SListPopBack(&head);
	SListPrint(head);
	SListPopBack(&head);
	SListPrint(head);
	SListDestroy(head);
}
void test2()
{
	SListNode* head = NULL;
	SListPushFront(&head, 3);
	SListPushFront(&head, 2);
	SListPushFront(&head, 1);
	/*SListPrint(head);
	SListPopFront(&head);
	SListPrint(head);
	SListPopFront(&head);
	SListPrint(head);
	SListPopFront(&head);
	SListPrint(head);
	SListPopFront(&head);*/
	SListPrint(head);
	SListNode*ret=SListFind(head,3);
	if (ret == NULL)
		printf("没找到\n");
	else
	{
		SListInsertAfter(ret,4);
	}
	SListPrint(head);

	ret = SListFind(head, 2);
	if (ret == NULL)
		printf("没找到\n");
	else
	{
		SListInsertAfter(ret, 4);
	}
	SListPrint(head);
	ret = SListFind(head, 1);
	if (ret == NULL)
		printf("没找到\n");
	else
	{
		SListInsertAfter(ret, 99);
	}
	SListPrint(head);
	SListDestroy(head);
}
void test3()
{
	SListNode* head = NULL;
	SListPushBack(&head, 1);
	SListPushBack(&head, 2);
	SListPushBack(&head, 3);
	SListPushBack(&head, 4);
	SListPushBack(&head,5);
	SListPrint(head);
	SListNode* ret = SListFind(head, 3);
	if (ret)
		SListEraseAfter(ret);
	SListPrint(head);
	ret = SListFind(head, 3);
	if (ret)
		SListEraseAfter(ret);
	SListPrint(head);
	SListDestroy(head);
}
int main()
{
	test3();
	free(NULL);
	return 0;
}