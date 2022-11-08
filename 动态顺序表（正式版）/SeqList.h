#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include<assert.h>
typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;

// 对数据的管理:增删查改 
//初始化顺序表
void SeqListInit(SeqList* ps);
//销毁顺序表
void SeqListDestroy(SeqList* ps);
//显示顺序表
void SeqListPrint(SeqList* ps);
//尾插
void SeqListPushBack(SeqList* ps, SLDateType x);
//头插
void SeqListPushFront(SeqList* ps, SLDateType x);
//头删
void SeqListPopFront(SeqList* ps);
//尾删
void SeqListPopBack(SeqList* ps);
// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos);
