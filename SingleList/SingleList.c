#define _CRT_SECURE_NO_WARNINGS

#include "SingleList.h"


// �����½ڵ�
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

// ��ӡ������
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

// β������
void ListPushBack(ListNode** pphead, ElementType e)
{
	// ����һ���½ڵ�
	ListNode* newnode = CreateNewnode(e);

	// ����ǿձ�
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//�ǿձ� β�����������ҵ�β��
		ListNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
	}

}

// ͷ������
void ListPushFront(ListNode** pphead, ElementType e)
{
	// ����һ���½ڵ�
	ListNode* newnode = CreateNewnode(e);

	newnode->next = *pphead;
	*pphead = newnode;

}


// β��ɾ��
// β��ɾ������Ҫ�ҵ�β����ͬʱ��Ҫ��¼��һ���ڵ�
void ListPopBack(ListNode** pphead)
{
	ListNode* tail = *pphead;
	ListNode* prev = NULL;

	// ����Ϊ��ʱ
	assert(*pphead != NULL);

	// ����ֻ��һ���ڵ�ʱ
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		// �������������������Ͻڵ�ʱ
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

// ͷ��ɾ��
void ListPopFront(ListNode** pphead)
{
	// ����Ϊ��ʱ
	assert(*pphead != NULL);

	ListNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

// ����Ԫ�����ݲ��ң������ҵ���Ľڵ�
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




