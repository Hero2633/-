#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLTDateType;
typedef struct SListNode
{
	SLTDateType val;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);

// �������ӡ
void SListPrint(const SListNode* plist);

// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x);

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x);

// �������βɾ
void SListPopBack(SListNode** pplist);

// ������ͷɾ
void SListPopFront(SListNode** pplist);

// ���������
SListNode* SListFind(const SListNode* plist, SLTDateType x);

// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x);

// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�
void SListEraseAfter(SListNode* pos);

// �����������
void SListDestroy ( SListNode* plist);