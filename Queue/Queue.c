#include"Queue.h"

//初始化队列
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}
//销毁队列
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = NULL;
	q->rear = NULL;
}

//开辟新节点
static QNode* BuyQNode(QDataType x)
{
	QNode* NewNode = (QNode*)malloc(sizeof(QNode));
	if (!NewNode)
	{
		printf("malloc fail!\n");
		exit(EXIT_FAILURE);
	}
	NewNode->next = NULL;
	NewNode->val = x;
	return NewNode;
}
//入队列
void QueuePush(Queue* q,QDataType x)
{
	assert(q);
	QNode* NewNode = BuyQNode(x);
	if (q->rear == NULL)
	{
		q->front = q->rear = NewNode;
	}
	else
	{
		q->rear->next = NewNode;
		q->rear = NewNode;
	}
}
//出队列
void QueuePop(Queue* q)
{
	assert(q);
	assert(QueueEmpty(q)==false);//判空
	QNode* next = q->front->next;
	free(q->front);
	q->front = next;
	if (q->front == NULL)//删除节点过后front指针指向NULL，表示无节点可删
		q->rear = q->front;
}
//队列判空
bool QueueEmpty(Queue* q)
{
	assert(q);
	return (q->front == q->rear && q->front == NULL);
}
//获取队头元素
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->val;
}
//获取队尾元素
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->rear->val;
}
//获取队列元素个数
size_t QueueSize(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	size_t count = 0;
	while (cur)
	{
		QNode* next = cur->next;
		count++;
		cur = next;
	}
	return count;
}