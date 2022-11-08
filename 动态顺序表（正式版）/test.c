#define  _CRT_SECURE_NO_WARNINGS 0
#include"SeqList.h"
void test1()
{
	SeqList tmp;
	//tmp.a = NULL;
	SeqListInit(&tmp);
	//SeqListPushBack(&tmp, 1);
	//SeqListPushBack(&tmp, 2);
	//SeqListPushBack(&tmp,3);
	//SeqListPushFront(&tmp, 1);
	//SeqListPushFront(&tmp, 2);
	///*SeqListPushFront(&tmp, 3);
	//SeqListPopFront(&tmp);
	//SeqListPopFront(&tmp);
	//SeqListPopFront(&tmp);
	//SeqListPopBack(&tmp);*/
	///*SeqListPopBack(&tmp);
	//SeqListPopBack(&tmp);
	//SeqListPopBack(&tmp);*/
	//int ret=SeqListFind(&tmp,32);
	//if (ret == -1)
	//	printf("没找到\n");
	//else
	//{
	//	printf("找到了,下标为:%d\n",ret);
	//}
	//SeqListPrint(&tmp);
	SeqListInsert(&tmp, 0, 1);
	SeqListInsert(&tmp, 0, 2);
	SeqListInsert(&tmp, 0, 3);
	SeqListInsert(&tmp, 0, 4);
	SeqListErase(&tmp,10);
	SeqListPrint(&tmp);
	SeqListDestroy(&tmp);
}
void test2()
{
	SeqList tmp;
	SeqListInit(&tmp);
	SeqListInsert(&tmp, -0, 1);//头插
	SeqListInsert(&tmp, 0, 2);//头插
	SeqListInsert(&tmp,0,3);//头插
	SeqListInsert(&tmp, tmp.size, 2);//尾插
	SeqListInsert(&tmp, tmp.size, 3);//尾插
	SeqListInsert(&tmp, tmp.size, 4);//尾插
	SeqListErase(&tmp, 0);//头删
	SeqListErase(&tmp, 0);//头删
	SeqListErase(&tmp, tmp.size);//尾删
	SeqListErase(&tmp,tmp.size-1);//尾删
	SeqListPrint(&tmp);
	SeqListDestroy(&tmp);
}
int main()
{
	//test1();
	test2();
	return 0;
}