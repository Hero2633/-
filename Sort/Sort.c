#include"Sort.h"
void PrintfArr(int* nums, int len)
{
	for (int i = 0; i < len; i++)
		printf("%d ",nums[i]);
	printf("\n");
}
static Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
//1°¢≤Â»Î≈≈–Ú
void InsertSort(int* nums, int len)//÷±Ω”≤Â»Î≈≈–Ú
{
	for (int i = 0; i < len - 1; i++)
	{
		int end=i;
		int key = nums[end + 1];
		while (end >= 0)
		{
			if (key >= nums[end])
				break;
			else
			{
				nums[end + 1] = nums[end];
				end--;
			}
		}
		nums[end + 1] = key;
	}
}
void ShellSort(int* nums, int len)//œ£∂˚≈≈–Ú
{
	int gap = len;
	while (gap > 1)
	{
		gap /= 2;
		for (int j = 0; j < gap; j++)
		{
			for (int i = j; i < len - gap; i += gap)
			{
				int end = i;
				int key = nums[end + gap];
				while (end >= 0)
				{
					if (key >= nums[end])
						break;
					else
					{
						nums[end + gap] = nums[end];
						end -= gap;
					}
				}
				nums[end + gap] = key;
			}
		}
	}
}
//2°¢—°‘Ò≈≈–Ú
void SelectSort(int* nums, int len)//—°‘Ò≈≈–Ú
{
	int left = 0;
	int right = len - 1;
	int maxi = 0;
	int mini = 0;
	while (left < right)
	{
		maxi = mini = left;
		for (int i = left; i <= right; i++)
		{
			if (nums[i] > nums[maxi])
				maxi = i;
			if (nums[i] < nums[mini])
				mini = i;
		}
		if (maxi == left)
			maxi = mini;
		Swap(nums + mini, nums + left++);
		Swap(nums+maxi,nums+right--);
	}
}
void AdjustDown(int* nums, int top, int end)
{
	int parent = top;
	int child = 2 * top + 1;
	while (child < end)
	{
		if (child + 1 < end && nums[child + 1] > nums[child])
			child += 1;
		if (nums[parent] >= nums[child])
			break;
		else
		{
			Swap(nums+parent,nums+child);
			parent = child;
			child = 2 * parent + 1;
		}
	}
}
void HeapSort(int* nums, int len)//∂—≈≈–Ú
{
	//1°¢…˝–ÚΩ®¥Û∂—£ªΩµ–ÚΩ®–°∂—
	for (int i = (len - 2) / 2; i >= 0; i--)
		AdjustDown(nums,i,len);
	int size = len;
	while (size)
	{
		Swap(nums,nums+(size--)-1);
		AdjustDown(nums,0,size);
	}
}
void BubbleSort(int* nums, int len)//√∞≈›≈≈–Ú
{
	int exchange = 0;
	for (int j = 0; j < len - 1; j++)
	{
		for (int i = 0; i < len -j- 1; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				Swap(nums + i, nums + i + 1);
				exchange = 1;
			}
		}
		if (!exchange)
			break;
	}
}
void Quick2(int* nums, int left, int right)
{
	if (left >= right)
		return;
	int begin = left;
	int end = right;
	int pig = left;
	int key = nums[pig];
	while (begin < end)
	{
		while (begin < end && nums[end] >= key)
			end--;
		nums[pig] = nums[end];
		pig = end;
		while (begin < end && nums[begin] <= key)
			begin++;
		nums[pig] = nums[begin];
		pig = begin;
	}
	nums[end] = key;
	Quick2(nums,left,end-1);
	Quick2(nums,end+1,right);
}
void Quick1(int* nums, int left, int right)
{
	if (left >= right)
		return;
	int begin = left;
	int end = right;
	int keyi = right;
	while (begin < end)
	{
		while (begin < end && nums[begin] <= nums[keyi])
			begin++;
		while (begin < end && nums[end] >= nums[keyi])
			end--;
		Swap(begin+nums,end+nums);
	}
	Swap(nums+keyi,nums+end);
	Quick1(nums,left,end-1);
	Quick1(nums, begin+1, right);
}

void QuickSort(int* nums, int len)//øÏÀŸ≈≈–Ú
{
	Quick2(nums,0,len-1);
}
void Merge(int* nums, int left, int right,int *tmp)
{
	if (left >= right)
		return;
	int mid = (right - left) / 2 + left;
	Merge(nums,left,mid,tmp);
	Merge(nums,mid+1,right,tmp);
	int begin1 = left;
	int begin2 = mid+1;
	int end1 = mid;
	int end2 = right;
	int k = 0;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (nums[begin1] < nums[begin2])
			tmp[k++] = nums[begin1++];
		else
			tmp[k++] = nums[begin2++];
	}
	while (begin1 <= end1)
		tmp[k++] = nums[begin1++];
	while (begin2 <= end2)
		tmp[k++] = nums[begin2++];
	for (int i = 0; i < k; i++)
		nums[left++] = tmp[i];
}
void MergeSort(int* nums, int len)
{
	int* tmp = (int*)malloc(sizeof(int) * len);
	Merge(nums,0,len-1,tmp);
	free(tmp);
}