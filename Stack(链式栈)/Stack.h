#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int DataType;
struct SListode
{
	DataType val;
	struct SListode* next;
};
typedef struct Stack
{
	int size;
	struct SListode* Head;
}ST;
//初始化栈
void InitStack(ST*ps);
//销毁栈
void DestroyStack(ST* ps);
//入栈
void StackPush(ST*ps,DataType x);
//出栈
void StackPop(ST*ps);
//统计栈里元素个数
size_t StackSize(ST*ps);
//判断栈是否为NULL
bool StackEmpty(ST* ps);
//获取栈顶元素
DataType StackTop(ST* ps);