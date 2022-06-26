#define _CRT_SECURE_NO_WARNINGS

#include "SingleList.h"


// 创建新节点
ListNode* CreateNewnode(ElementType e)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL)
	{
		exit(-1);
	}
	newnode->data = e;
	newnode->next = NULL;

	return newnode;
}

// 打印单链表
void printList(ListNode* phead)
{
	ListNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

// 尾部插入
void ListPushBack(ListNode** pphead, ElementType e)
{
	// 创建一个新节点
	ListNode* newnode = CreateNewnode(e);

	// 如果是空表
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//非空表 尾部插入首先找到尾部
		ListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}

// 头部插入
void ListPushFront(ListNode** pphead, ElementType e)
{
	// 创建一个新节点
	ListNode* newnode = CreateNewnode(e);

	newnode->next = *pphead;
	*pphead = newnode;

}


// 尾部删除
// 尾部删除首先要找到尾部，同时还要记录上一个节点
void ListPopBack(ListNode** pphead)
{
	ListNode* tail = *pphead;
	ListNode* prev = NULL;

	// 链表为空时
	assert(*pphead != NULL);

	// 链表只有一个节点时
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		// 链表有两个或两个以上节点时
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		tail = NULL;
		prev->next = NULL;

	}

}

// 头部删除
void ListPopFront(ListNode** pphead)
{
	// 链表为空时
	assert(*pphead != NULL);

	ListNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

// 根据元素内容查找，返回找到后的节点
ListNode* ListFind(ListNode* phead, ElementType e)
{
	ListNode* cur = phead;

	while (cur != NULL)
	{
		if (cur->data == e)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}

	return NULL;
}





