#include"Heap.h"
//堆的初始化
void HeapInit(Hp* php)
{
	assert(php);
	php->Capcity = 0;
	php->nums = NULL;
	php->size = 0;
}
//堆的销毁
void HeapDestroy(Hp* php)
{
	assert(php);
	free(php->nums);
	php->Capcity = 0;
	php->size = 0;
}
static void Swap(HPDateType* p1, HPDateType* p2)
{
	HPDateType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
//扩容
static void Check_Capcity(Hp*php)
{
	assert(php);
	//容量满
	if (php->size == php->Capcity)
	{
		int NewCapcity = php->Capcity == 0 ? 4 : php->Capcity * 2;
		HPDateType* tmp = (HPDateType*)realloc(php->nums,sizeof(HPDateType)*NewCapcity);
		if (!tmp)
			exit(EXIT_FAILURE);
		php->nums = tmp;
		php->Capcity = NewCapcity;
	}
}
static void AdjustUp(HPDateType* nums, int size, int child)//向上调整
{
	 child = size - 1;
	int parent = (size - 2) / 2;
	while (child > 0)
	{
		parent = (child - 1) / 2;
		if (nums[child] <nums[parent])//说明插入数据不能保持堆是一个大堆，需要调整
		{
			Swap(nums + child,nums + parent);
			child = parent;
		}
		else
			break;
	}
}
static void AdjustDown(HPDateType* nums, int size)//向下调整
{
	int parent = 0;
	int child = 2 * parent + 1;//假设左孩子是两个孩子之间最大的;
	while (child < size)
	{
		//验证假设对不对
		if (child <size - 1 &&nums[child + 1] <nums[child])//不满足假设需要调整
		{
			child++;
		}
		if (nums[parent] >nums[child])//说明不满足大堆需要调整
		{
			Swap(nums + parent, nums + child);
			parent = child;
			child = 2 * parent + 1;
		}
		else//满足大堆
			break;
	}
}
//堆的插入
void HeapPush(Hp* php, HPDateType x)
{
	assert(php);
	Check_Capcity(php);
	php->nums[php->size] = x;
	php->size++;
	AdjustUp(php->nums,php->size,php->size-1);
}
//堆的删除
void HeapPop(Hp* php)
{
	assert(php);
	assert(HeapEmpty(php)==false);
	Swap(php->nums,php->nums+php->size-1);
	php->size--;
	AdjustDown(php->nums,php->size);
}
//堆的判空
bool HeapEmpty(Hp* php)
{
	assert(php);
	return php->size == 0;
}
//获取堆顶数据
HPDateType HeapTop(Hp* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->nums[0];
}
//获取堆的元素个数
int HeapSize(Hp* php)
{
	assert(php);
	return php->size;
}