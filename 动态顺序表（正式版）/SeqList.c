#define  _CRT_SECURE_NO_WARNINGS 0
#include"SeqList.h"
static void Check_Capacity(SeqList* ps)
{
    if (ps->capacity == ps->size)//�������˻��߻�û���ٿռ�
    {
        size_t NewCapacity = (ps->capacity == 0) ? 4 : ps->capacity * 2;
        int* tmp = (int*)realloc(ps->a, NewCapacity * sizeof(int));
        if (tmp == NULL)
            exit(-1);
        ps->a = tmp;
        ps->capacity = NewCapacity;
    }
}
void SeqListInit(SeqList* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->capacity = 0;
    ps->size = 0;
}
void SeqListDestroy(SeqList* ps)
{
    assert(ps);
        free(ps->a);
        ps->capacity = 0;
        ps->size = 0;
}
void SeqListPrint(SeqList* ps)
{
    assert(ps);
    if (ps->size)
    {
        int len = ps->size;
        for (int i = 0; i <len; i++)
            printf("%d ", ps->a[i]);
    }
    else
        printf("NULL\n");
}
void SeqListPushBack(SeqList* ps, SLDateType x)
{
    assert(ps);
    Check_Capacity(ps);
    //�ڲ�������֮ǰҪ�ȼ��һ���Ƿ���ʣ������
    ps->a[ps->size] = x;
    ps->size++;
}
void SeqListPushFront(SeqList* ps, SLDateType x)
{
    assert(ps);
    Check_Capacity(ps);
    int end = ps->size - 1;
    for (end; end >= 0; end--)
        ps->a[end + 1] = ps->a[end];
    ps->a[end + 1] = x;
    ps->size++;

}
void SeqListPopFront(SeqList* ps)
{
    assert(ps);
    assert(ps->size>0);//��ûԪ���˾Ͳ�ɾ��
    int begin = 1;
    int len = ps->size;
    for (begin; begin < len; begin++)
        ps->a[begin - 1] = ps->a[begin];
    ps->size--;
}
void SeqListPopBack(SeqList* ps)
{
    assert(ps);
    assert(ps->size>0);
    ps->size--;
}
int SeqListFind(SeqList* ps, SLDateType x)
{
    assert(ps);
    assert(ps->size>0);
    int len = ps->size;
    for (int i = 0; i < len; i++)
        if (ps->a[i] == x)
            return i;
    return -1;
}
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
    assert(ps);
    //���pos�����Ҵ��������Ϸ���Χ?
    assert(pos<=ps->size);
    Check_Capacity(ps);
    int end = ps->size - 1;
    int target = pos;
    for (; end >= target; end--)//����ᷢ������ת������ð�pos����ת��һ��
        ps->a[end + 1] = ps->a[end];
    ps->a[end+1] = x;
    ps->size++;

}

void SeqListErase(SeqList* ps, size_t pos)
{
    assert(ps);
    assert(ps->size>0);
    //pos�Ҵ�?
    assert(pos<=ps->size);
    int begin = pos + 1;
    int len = ps->size;
    for (; begin < len; begin++)
    {
        ps->a[begin - 1] = ps->a[begin];
    }
    ps->size--;
}