#include"Heap.h"
//�ѵĳ�ʼ��
void HeapInit(Hp* php)
{
	assert(php);
	php->Capcity = 0;
	php->nums = NULL;
	php->size = 0;
}
//�ѵ�����
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
//����
static void Check_Capcity(Hp*php)
{
	assert(php);
	//������
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
static void AdjustUp(HPDateType* nums, int size, int child)//���ϵ���
{
	 child = size - 1;
	int parent = (size - 2) / 2;
	while (child > 0)
	{
		parent = (child - 1) / 2;
		if (nums[child] <nums[parent])//˵���������ݲ��ܱ��ֶ���һ����ѣ���Ҫ����
		{
			Swap(nums + child,nums + parent);
			child = parent;
		}
		else
			break;
	}
}
static void AdjustDown(HPDateType* nums, int size)//���µ���
{
	int parent = 0;
	int child = 2 * parent + 1;//������������������֮������;
	while (child < size)
	{
		//��֤����Բ���
		if (child <size - 1 &&nums[child + 1] <nums[child])//�����������Ҫ����
		{
			child++;
		}
		if (nums[parent] >nums[child])//˵������������Ҫ����
		{
			Swap(nums + parent, nums + child);
			parent = child;
			child = 2 * parent + 1;
		}
		else//������
			break;
	}
}
//�ѵĲ���
void HeapPush(Hp* php, HPDateType x)
{
	assert(php);
	Check_Capcity(php);
	php->nums[php->size] = x;
	php->size++;
	AdjustUp(php->nums,php->size,php->size-1);
}
//�ѵ�ɾ��
void HeapPop(Hp* php)
{
	assert(php);
	assert(HeapEmpty(php)==false);
	Swap(php->nums,php->nums+php->size-1);
	php->size--;
	AdjustDown(php->nums,php->size);
}
//�ѵ��п�
bool HeapEmpty(Hp* php)
{
	assert(php);
	return php->size == 0;
}
//��ȡ�Ѷ�����
HPDateType HeapTop(Hp* php)
{
	assert(php);
	assert(!HeapEmpty(php));
	return php->nums[0];
}
//��ȡ�ѵ�Ԫ�ظ���
int HeapSize(Hp* php)
{
	assert(php);
	return php->size;
}