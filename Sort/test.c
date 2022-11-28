#include"Sort.h"
void InsertSortTest()
{
	int nums[] = {6,1,2,7,9,3,4,5,10,8};
	int len = sizeof(nums) / sizeof(int);
	InsertSort(nums,len);
	PrintfArr(nums,len);
}
void ShellSortTest()
{
	int nums[] = { 6,1,2,7,9,3,4,5,10,8 };
	int len = sizeof(nums) / sizeof(int);
	ShellSort(nums,len);
	PrintfArr(nums, len);
}
void SelectSortTest()
{
	int nums[] = { 6,1,2,7,9,3,4,5,10,8 };
	int len = sizeof(nums) / sizeof(int);
	SelectSort(nums, len);
	PrintfArr(nums, len);
}
void HeapSortTest()
{
	int nums[] = { 6,1,2,7,9,3,4,5,10,8 };
	int len = sizeof(nums) / sizeof(int);
	HeapSort(nums, len);
	PrintfArr(nums, len);
}
void QuickSortTest()
{
	int nums[] = { 6,1,2,7,9,3,4,5,10,8 };
	int len = sizeof(nums) / sizeof(int);
	QuickSort(nums, len);
	PrintfArr(nums, len);
}
void BubbleSorTest()
{
	int nums[] = { 6,1,2,7,9,3,4,5,10,8 };
	int len = sizeof(nums) / sizeof(int);
	BubbleSort(nums, len);
	PrintfArr(nums, len);
}
void MergeSorTest()
{
	int nums[] = { 6,1,2,7,9,3,4,5,10,8 };
	int len = sizeof(nums) / sizeof(int);
	MergeSort(nums, len);
	PrintfArr(nums, len);
}
int main()
{
	//InsertSortTest();
	//ShellSortTest();
	SelectSortTest();
	HeapSortTest();
	//QuickSortTest();
	//BubbleSorTest();
	//MergeSorTest();
	return 0;
}