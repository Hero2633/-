#include"DList.h"
void test1()
{
	ListNode* plist = NULL;
	plist = ListCreate(-1);//创建哨兵位头节点
	InitDummyHead(plist);//初始化哨兵位的头节点
	ListPrint(plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist,3);
	ListPrint(plist);

	ListPopBack(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListPopBack(plist);
	ListPrint(plist);
	ListPushFront(plist, 9);
	ListPushFront(plist, 8);
	ListPushFront(plist, 7);
	ListPushFront(plist,6);
	ListPrint(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);

	ListDestory(plist);
}
void test2()
{
	ListNode* plist = ListCreate(-1);
	InitDummyHead(plist);
	//ListPopFront(plist);
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist,4);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);

	ListPopFront(plist);

	ListPrint(plist);

	ListDestory(plist);
}
void test3()
{
	ListNode* plist = ListCreate(-1);
	InitDummyHead(plist);
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist,4);
	ListPrint(plist);
	/*ListNode*ret=ListFind(plist,4);
	ListInsert(plist->next,0);
	ListPrint(plist);*/
	ListDestory(plist);
}
void test4()
{
	ListNode* plist = ListCreate(-1);
	InitDummyHead(plist);
	ListInsert(plist, 1);//相当于尾插
	ListInsert(plist, 2);//相当于尾插
	ListInsert(plist,3);//相当于尾插
	ListInsert(plist->next, 4);//相当于头插
	ListInsert(plist->next, 5);//相当于头插
	ListInsert(plist->next, 6);//相当于头插
	ListInsert(plist->next, 7);//相当于头插
	ListPrint(plist);
	ListErase(plist->next);//相当于头删
	ListPrint(plist);
	ListErase(plist->prev);//相当于尾删;
	ListPrint(plist);
	ListDestory(plist);
}
int main()
{
	test4();
	return 0;
}