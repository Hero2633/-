#include"Queue.h"
void test1()
{
	Queue tmp;
	QueueInit(&tmp);
	QueuePush(&tmp, 1);
	QueuePush(&tmp, 2);
	QueuePush(&tmp, 3);
	QueuePush(&tmp,4);
	QueuePop(&tmp);
	QueuePop(&tmp);
	QueuePop(&tmp);
	QueuePop(&tmp);
	QueuePush(&tmp,5);

	size_t len = QueueSize(&tmp);
	int front = QueueFront(&tmp);
	int rear = QueueBack(&tmp);
	printf("%d %d\n",front,rear);
	printf("%zd\n",len);
	QueueDestroy(&tmp);
}
int main()
{
	test1();			

	return 0;
}