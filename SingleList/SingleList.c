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


// ��posλ��֮ǰȥ����һ���ڵ�
void ListInsert(ListNode** pphead, ListNode* pos, ElementType e)
{
	// ����һ���µĽڵ�
	ListNode* newnode = CreateNewnode(e);

	assert(*pphead != NULL);

	if (*pphead == pos)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		// �ҵ�pos��ǰһ���ڵ�
		ListNode* posPrev = *pphead;

		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}

		posPrev->next = newnode;
		newnode->next = pos;

	}

}

// ��posλ��֮��ȥ����һ���ڵ�
void ListInsertAfter(ListNode* pos, ElementType e)
{
	// ����һ���µĽڵ�
	ListNode* newnode = CreateNewnode(e);
	newnode->next = pos->next;
	pos->next = newnode;

}


// ɾ��posλ�ýڵ�
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
		// �ҵ�pos��ǰһ���ڵ�
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

// ��posλ��֮��ȥɾ��һ���ڵ�
void ListEraseAfter(ListNode* pos)
{
	// pos->next����Ϊ�գ�
	assert(pos->next);

	ListNode* next = pos->next;
	pos->next = next->next;
	free(next);
	next = NULL;

}

// ��������
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


// ������ĳ���
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


// �������е�posλ�ò���һ���ڵ㣨posΪ�����λ��
int ListInsertByPos(ListNode** pphead, int pos, ElementType e)
{
	assert(pphead && pos >= 1 && pos <= ListLength(*pphead) + 1);

	// pos == 1 ʱ���൱��ͷ��
	if (pos == 1)
	{
		ListPushFront(pphead, e);
		return 1;
	}

	// �����½ڵ�
	ListNode* newnode = CreateNewnode(e);

	// �ҵ�pos��ǰһ���ڵ�
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

// �ж������Ƿ�Ϊ��
int ListEmpty(ListNode* phead)
{
	return phead == NULL;
}

// ��posλ��ȥɾ��һ���ڵ�(posΪ�߼�λ��)
int ListEraseByPos(ListNode** pphead, int pos)
{
	assert(pphead && pos >= 1 && pos <= ListLength(*pphead));

	// �ж������Ƿ�Ϊ��
	if (ListEmpty(*pphead))
	{
		return 0;
	}

	// ͷɾ
	if (pos == 1)
	{
		ListPopFront(pphead);
		return 1;
	}

	// �ҵ�pos��ǰһ���ڵ�
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









