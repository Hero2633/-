#include"Heap.h"
void Printf(HPDateType* nums, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf("%d ",nums[i]);
	}
	putchar('\n');
}
void test1()
{
	Hp hp;
	HeapInit(&hp);
	int arr[] = {3,2,1};
	int len = sizeof(arr) / sizeof(int);
	//建堆的过程…………时间复杂度O（NlogN）
	for (int i = 0; i < len; i++)
	{
		HeapPush(&hp, arr[i]);
	}
	for (int i = 0; i < 2; i++)
	{
		printf("%d ",HeapTop(&hp));
		//HeapPop(&hp);
	}
	/*Printf(hp.nums,hp.size);
	HeapPop(&hp);
	Printf(hp.nums,hp.size);*/
	HeapDestroy(&hp);
}
int main()
{
	test1();
	return 0;
}