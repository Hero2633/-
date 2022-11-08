#pragma once
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<assert.h>
typedef char DataType;
typedef struct Stack
{
	DataType* nums;
	int capcity;
	int top;
}ST;
//初始化栈
void InitStack(ST* ps);
//销毁栈
void DestroyStack(ST* ps);
//入栈
void StackPush(ST* ps,DataType x);
//出栈
void StackPop(ST*ps);
//判断栈是否为NULL
bool StackEmpty(ST* ps);
//统计栈的元素
size_t StackSize(ST* ps);
//获取栈顶元素个数
DataType StackTop(ST*ps);