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


// 在pos位置之前去插入一个节点
void ListInsert(ListNode** pphead, ListNode* pos, ElementType e)
{
	// 创建一个新的节点
	ListNode* newnode = CreateNewnode(e);

	assert(*pphead != NULL);

	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		// 找到pos的前一个节点
		ListNode* posPrev = *pphead;

		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}

		posPrev->next = newnode;
		newnode->next = pos;

	}

}

// 在pos位置之后去插入一个节点
void ListInsertAfter(ListNode* pos, ElementType e)
{
	// 创建一个新的节点
	ListNode* newnode = CreateNewnode(e);
	newnode->next = pos->next;
	pos->next = newnode;

}


// 删除pos位置节点
void ListErase(ListNode** pphead, ListNode* pos)
{
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
		pos = NULL;
	}
	else
	{
		// 找到pos的前一个节点
		ListNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}

		posPrev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

// 在pos位置之后去删除一个节点
void ListEraseAfter(ListNode* pos)
{
	// pos->next不能为空！
	assert(pos->next);

	ListNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;

}

// 销毁链表
void ListDestroy(ListNode** pphead)
{
	assert(pphead);

	ListNode* cur = *pphead;
	while (cur)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}

	*pphead = NULL;

}


// 求链表的长度
int ListLength(ListNode* phead)
{
	ListNode* cur = phead;
	int i = 0;
	while (cur)
	{
		i++;
		cur = cur->next;
	}

	return i;
}


// 在链表中的pos位置插入一个节点（pos为链表的位序）
int ListInsertByPos(ListNode** pphead, int pos, ElementType e)
{
	assert(pphead && pos >= 1 && pos <= ListLength(*pphead) + 1);

	// pos == 1 时，相当于头插
	if (pos == 1)
	{
		ListPushFront(pphead, e);
		return 1;
	}

	// 创建新节点
	ListNode* newnode = CreateNewnode(e);

	// 找到pos的前一个节点
	ListNode* p = *pphead;
	int i = 0;
	for (i = 1; i < pos - 1; i++)
	{
		p = p->next;
	}

	newnode->next = p->next;
	p->next = newnode;

	return 1;

}

// 判断链表是否为空
int ListEmpty(ListNode* phead)
{
	return phead == NULL;
}

// 在pos位置去删除一个节点(pos为逻辑位序)
int ListEraseByPos(ListNode** pphead, int pos)
{
	assert(pphead && pos >= 1 && pos <= ListLength(*pphead));

	// 判断链表是否为空
	if (ListEmpty(*pphead))
	{
		return 0;
	}

	// 头删
	if (pos == 1)
	{
		ListPopFront(pphead);
		return 1;
	}

	// 找到pos的前一个节点
	ListNode* p = *pphead;
	int i = 0;
	for (i = 1; i < pos - 1; i++)
	{
		p = p->next;
	}

	ListNode* q = p->next;
	p->next = q->next;
	free(q);

	return 1;
}









