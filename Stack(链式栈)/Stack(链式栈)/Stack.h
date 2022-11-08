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
//��ʼ��ջ
void InitStack(ST*ps);
//����ջ
void DestroyStack(ST* ps);
//��ջ
void StackPush(ST*ps,DataType x);
//��ջ
void StackPop(ST*ps);
//ͳ��ջ��Ԫ�ظ���
size_t StackSize(ST*ps);
//�ж�ջ�Ƿ�ΪNULL
bool StackEmpty(ST* ps);
//��ȡջ��Ԫ��
DataType StackTop(ST* ps);