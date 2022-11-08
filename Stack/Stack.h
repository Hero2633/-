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
//��ʼ��ջ
void InitStack(ST* ps);
//����ջ
void DestroyStack(ST* ps);
//��ջ
void StackPush(ST* ps,DataType x);
//��ջ
void StackPop(ST*ps);
//�ж�ջ�Ƿ�ΪNULL
bool StackEmpty(ST* ps);
//ͳ��ջ��Ԫ��
size_t StackSize(ST* ps);
//��ȡջ��Ԫ�ظ���
DataType StackTop(ST*ps);