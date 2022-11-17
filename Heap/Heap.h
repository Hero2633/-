#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int HPDateType;
typedef struct Heap
{
	HPDateType* nums;
	int size;
	int Capcity;
}Hp;
 //堆的初始化
void HeapInit(Hp*php);
//堆的销毁
void HeapDestroy(Hp*php);
//堆的插入//时间复杂度O（logN）
void HeapPush(Hp*php,HPDateType x);
//堆的删除//时间复杂度O（logN）
void HeapPop(Hp* php);
//获取堆顶数据
HPDateType HeapTop(Hp*php);
//获取堆的元素个数
int HeapSize(Hp*php);
//堆的判空
bool HeapEmpty(Hp*php);

