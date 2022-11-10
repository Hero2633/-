#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>
// 链式结构：表示队列 
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* next;
	QDataType val;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;
 
//初始化队列
void QueueInit(Queue*q);
//销毁队列
void QueueDestroy(Queue*q);
//入队列
void QueuePush(Queue*q,QDataType x);
//出队列
void QueuePop(Queue*q);
//获取队头元素
QDataType QueueFront(Queue*q);
//获取队尾元素
QDataType QueueBack(Queue* q);
//获取队列元素个数
size_t QueueSize(Queue*q);
//队列判空
bool QueueEmpty(Queue*q);