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

// 创建新节点
ListNode* CreateNewnode(ElementType e);

// 打印单链表
void printList(ListNode* pphead);

// 尾部插入
void ListPushBack(ListNode** pphead, ElementType e);

// 头部插入
void ListPushFront(ListNode** pphead, ElementType e);

// 尾部删除
void ListPopBack(ListNode** pphead);

// 头部删除
void ListPopFront(ListNode** pphead);

// 根据元素内容查找
ListNode* ListFind(ListNode* phead, ElementType e);

// 在pos位置之前去插入一个节点
void ListInsert(ListNode** pphead, ListNode* pos, ElementType e);

// 在pos位置之后去插入一个节点
void ListInsertAfter(ListNode* pos, ElementType e);

// 在链表中的pos位置插入一个节点（pos为链表的位序）
void ListInsertByPos(ListNode** pphead, int pos, ElementType e);

// 删除pos位置节点
void ListErase(ListNode** pphead, ListNode* pos);

// 在pos位置之后去删除一个节点
void ListEraseAfter(ListNode* pos);

// 在pos位置去删除一个节点(pos为位序)
void ListEraseByPos(ListNode** pphead, int pos);

// 销毁链表
void ListDestroy(ListNode** pphead);