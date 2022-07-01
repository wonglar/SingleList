#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ElementType;

typedef struct ListNode
{
	ElementType data;
	struct ListNode* next;

}ListNode;

// �����½ڵ�
ListNode* CreateNewnode(ElementType e);

// ��ӡ������
void printList(ListNode* pphead);

// β������
void ListPushBack(ListNode** pphead, ElementType e);

// ͷ������
void ListPushFront(ListNode** pphead, ElementType e);

// β��ɾ��
void ListPopBack(ListNode** pphead);

// ͷ��ɾ��
void ListPopFront(ListNode** pphead);

// ����Ԫ�����ݲ���
ListNode* ListFind(ListNode* phead, ElementType e);

// ��posλ��֮ǰȥ����һ���ڵ�
void ListInsert(ListNode** pphead, ListNode* pos, ElementType e);

// ��posλ��֮��ȥ����һ���ڵ�
void ListInsertAfter(ListNode* pos, ElementType e);

// �������е�posλ�ò���һ���ڵ㣨posΪ������߼�λ��
int ListInsertByPos(ListNode** pphead, int pos, ElementType e);

// ɾ��posλ�ýڵ�
void ListErase(ListNode** pphead, ListNode* pos);

// ��posλ��֮��ȥɾ��һ���ڵ�
void ListEraseAfter(ListNode* pos);

// ��posλ��ȥɾ��һ���ڵ�(posΪ�߼�λ��)
int ListEraseByPos(ListNode** pphead, int pos);

// ��������
void ListDestroy(ListNode** pphead);

// ������ĳ���
int ListLength(ListNode* phead);

// �ж������Ƿ�Ϊ��
int ListEmpty(ListNode* phead);