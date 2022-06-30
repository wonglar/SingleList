#define _CRT_SECURE_NO_WARNINGS
#include "SingleList.h"

// ����β������
void TestSingleList01()
{
	ListNode* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);

	printList(list);
}


// ����ͷ������
void TestSingleList02()
{
	ListNode* list = NULL;
	ListPushFront(&list, 4);
	ListPushFront(&list, 3);
	ListPushFront(&list, 2);
	ListPushFront(&list, 1);

	printList(list);
}

// ����β��ɾ��
void TestSingleList03()
{
	ListNode* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	printList(list);

	ListPopBack(&list);
	ListPopBack(&list);
	ListPopBack(&list);
	printList(list);
}

// ����ͷ��ɾ��
void TestSingleList04()
{
	ListNode* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	printList(list);

	ListPopFront(&list);
	ListPopFront(&list);
	ListPopFront(&list);
	ListPopFront(&list);

	printList(list);

}

// ���Ը���Ԫ�����ݽ��в���
void TestSingleList05()
{
	ListNode* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	ListPushBack(&list, 3);
	printList(list);

	int goal = 3;
	ListNode* node = ListFind(list, goal);
	
	int i = 0;
	while (node != NULL)
	{
		i++;
		node = ListFind(node->next, goal);
	}
	 
	printf("һ���ҵ��� %d ��ֵΪ %d �Ľڵ�\n", i, goal);

	printf("---------------------------------------------\n");

	// ��ֵΪ3�Ķ��޸�Ϊ30
	node = ListFind(list, 3);
	while(node != NULL)
	{
		node->data = 30;
		node = ListFind(node->next, 3);
	}
	printList(list);
}


// ������posλ��֮ǰȥ����һ���ڵ�
void TestSingleList06()
{
	ListNode* list = NULL;
	/*ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);*/
	printList(list);

	ListNode* pos = ListFind(list, 1);

	if (pos)
	{
		ListInsert(&list, pos, 10);
		printList(list);
	}
}

// ������posλ��֮��ȥ����һ���ڵ�
void TestSingleList07()
{
	ListNode* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	printList(list);

	ListNode* pos = ListFind(list, 2);
	if (pos)
	{
		ListInsertAfter(pos, 20);
		printList(list);
	}
}

// ����ɾ��posλ�ýڵ�
void TestSingleList08()
{
	ListNode* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	printList(list);

	ListNode* pos = ListFind(list, 1);
	if (pos)
	{
		ListErase(&list, pos);
		printList(list);
	}

}

// ������posλ��֮��ɾ��һ���ڵ�
void TestSingleList09()
{
	ListNode* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	printList(list);

	ListNode* pos = ListFind(list, 4);
	if (pos)
	{
		ListEraseAfter(pos);
		printList(list);
	}

}

// ������������
void TestSingleList10()
{
	ListNode* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	printList(list);

	ListDestroy(&list);

}

int main()
{
	//// ����β������
	//TestSingleList01();

	//// ����ͷ������
	//TestSingleList02();

	// ����β��ɾ��
	//TestSingleList03();

	// ����ͷ��ɾ��
	//TestSingleList04();

	// ���Ը���Ԫ�����ݽ��в���
	//TestSingleList05();

	// ������posλ��֮ǰȥ����һ���ڵ�
	//TestSingleList06();

	// ������posλ��֮��ȥ����һ���ڵ�
	//TestSingleList07();

	// ����ɾ��posλ�ýڵ�
	//TestSingleList08();

	// ������posλ��֮��ɾ��һ���ڵ�
	//TestSingleList09();

	// ������������
	TestSingleList10();

	return 0;
}