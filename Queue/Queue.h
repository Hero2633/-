#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
// ��ʽ�ṹ����ʾ���� 
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* next;
	QDataType val;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;
 
//��ʼ������
void QueueInit(Queue*q);
//���ٶ���
void QueueDestroy(Queue*q);
//�����
void QueuePush(Queue*q,QDataType x);
//������
void QueuePop(Queue*q);
//��ȡ��ͷԪ��
QDataType QueueFront(Queue*q);
//��ȡ��βԪ��
QDataType QueueBack(Queue* q);
//��ȡ����Ԫ�ظ���
size_t QueueSize(Queue*q);
//�����п�
bool QueueEmpty(Queue*q);