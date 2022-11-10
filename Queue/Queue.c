#include"Queue.h"

//��ʼ������
void QueueInit(Queue* q)
{
	assert(q);
	q->front = NULL;
	q->rear = NULL;
}
//���ٶ���
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

//�����½ڵ�
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
//�����
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
//������
void QueuePop(Queue* q)
{
	assert(q);
	assert(QueueEmpty(q)==false);//�п�
	QNode* next = q->front->next;
	free(q->front);
	q->front = next;
	if (q->front == NULL)//ɾ���ڵ����frontָ��ָ��NULL����ʾ�޽ڵ��ɾ
		q->rear = q->front;
}
//�����п�
bool QueueEmpty(Queue* q)
{
	assert(q);
	return (q->front == q->rear && q->front == NULL);
}
//��ȡ��ͷԪ��
QDataType QueueFront(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->front->val;
}
//��ȡ��βԪ��
QDataType QueueBack(Queue* q)
{
	assert(q);
	assert(!QueueEmpty(q));
	return q->rear->val;
}
//��ȡ����Ԫ�ظ���
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