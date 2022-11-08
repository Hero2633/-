#define  _CRT_SECURE_NO_WARNINGS 0
#include"SeqList.h"
static void Check_Capacity(SeqList* ps)
{
    if (ps->capacity == ps->size)//容量满了或者还没开辟空间
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
    //在插入数据之前要先检查一下是否还有剩余容量
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
    assert(ps->size>0);//都没元素了就不删了
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
    //如果pos给我乱传，超出合法范围?
    assert(pos<=ps->size);
    Check_Capacity(ps);
    int end = ps->size - 1;
    int target = pos;
    for (; end >= target; end--)//这里会发生向上转换，最好把pos类型转换一下
        ps->a[end + 1] = ps->a[end];
    ps->a[end+1] = x;
    ps->size++;

}

void SeqListErase(SeqList* ps, size_t pos)
{
    assert(ps);
    assert(ps->size>0);
    //pos乱传?
    assert(pos<=ps->size);
    int begin = pos + 1;
    int len = ps->size;
    for (; begin < len; begin++)
    {
        ps->a[begin - 1] = ps->a[begin];
    }
    ps->size--;
}