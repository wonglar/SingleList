#define _CRT_SECURE_NO_WARNINGS
#include "SingleList.h"

// 测试尾部插入
void TestSingleList01()
{
	ListNode* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);

	printList(list);
}


// 测试头部插入
void TestSingleList02()
{
	ListNode* list = NULL;
	ListPushFront(&list, 4);
	ListPushFront(&list, 3);
	ListPushFront(&list, 2);
	ListPushFront(&list, 1);

	printList(list);
}

// 测试尾部删除
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

// 测试头部删除
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

// 测试根据元素内容进行查找
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
	 
	printf("一共找到了 %d 个值为 %d 的节点\n", i, goal);

	printf("---------------------------------------------\n");

	// 将值为3的都修改为30
	node = ListFind(list, 3);
	while(node != NULL)
	{
		node->data = 30;
		node = ListFind(node->next, 3);
	}
	printList(list);
}


// 测试在pos位置之前去插入一个节点
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

// 测试在pos位置之后去插入一个节点
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

// 测试删除pos位置节点
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

// 测试在pos位置之后删除一个节点
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

// 测试销毁链表
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


// 测试求链表的长度
void TestSingleList11()
{
	ListNode* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	printList(list);

	int length = ListLength(list);
	printf("%d\n", length);
}

// 测试在链表中的pos位置插入一个节点（pos为链表的逻辑位序）
void TestSingleList12()
{
	ListNode* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	printList(list);

	ListInsertByPos(&list, 5, 55);
	printList(list);
	
}

// 测试在pos位置去删除一个节点(pos为逻辑位序)
void TestSingleList13()
{
	ListNode* list = NULL;
	ListPushBack(&list, 1);
	ListPushBack(&list, 2);
	ListPushBack(&list, 3);
	ListPushBack(&list, 4);
	printList(list);

	ListEraseByPos(&list, 3);
	printList(list);
}

int main()
{
	//// 测试尾部插入
	//TestSingleList01();

	//// 测试头部插入
	//TestSingleList02();

	// 测试尾部删除
	//TestSingleList03();

	// 测试头部删除
	//TestSingleList04();

	// 测试根据元素内容进行查找
	//TestSingleList05();

	// 测试在pos位置之前去插入一个节点
	//TestSingleList06();

	// 测试在pos位置之后去插入一个节点
	//TestSingleList07();

	// 测试删除pos位置节点
	//TestSingleList08();

	// 测试在pos位置之后删除一个节点
	//TestSingleList09();

	// 测试销毁链表
	//TestSingleList10();

	// 测试求链表的长度
	//TestSingleList11();

	// 测试在链表中的pos位置插入一个节点（pos为链表的逻辑位序）
	//TestSingleList12();

	// 测试在pos位置去删除一个节点(pos为逻辑位序)
	TestSingleList13();

	return 0;
}