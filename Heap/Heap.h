#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
typedef int HPDateType;
typedef struct Heap
{
	HPDateType* nums;
	int size;
	int Capcity;
}Hp;
 //�ѵĳ�ʼ��
void HeapInit(Hp*php);
//�ѵ�����
void HeapDestroy(Hp*php);
//�ѵĲ���//ʱ�临�Ӷ�O��logN��
void HeapPush(Hp*php,HPDateType x);
//�ѵ�ɾ��//ʱ�临�Ӷ�O��logN��
void HeapPop(Hp* php);
//��ȡ�Ѷ�����
HPDateType HeapTop(Hp*php);
//��ȡ�ѵ�Ԫ�ظ���
int HeapSize(Hp*php);
//�ѵ��п�
bool HeapEmpty(Hp*php);

