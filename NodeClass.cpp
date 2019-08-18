#include "stdafx.h"
#include "NodeClass.h"
#include <iostream>
using namespace std;

NodeClass::NodeClass()
{

	Node* a = new Node(1);
	a->next = NULL;

	Node* b = new Node(2);
	b->next = a;

	Node* c = new Node(3);
	c->next = b;

	Node* firstNode = new Node(0);
	firstNode->next = c;

	//DeleteNode(firstNode, a);
	DeleteNodeO1(firstNode, a);
}
 



NodeClass::~NodeClass()
{
}



//双向链表删除更快，是因为，删除的时候，直接找被删除节点的父节点指向被删除节点的子节点。
//在O(1)时间范围内删除Node节点
bool NodeClass::DeleteNodeO1(Node* mNode, Node* waitDeleteNode)
{

	if (!mNode || !waitDeleteNode)
		return false;


	Node* sonNode = waitDeleteNode->next;

	//如果不是是尾节点
	if (sonNode != NULL)
	{
		//找到上一个节点
		waitDeleteNode->value = sonNode->value;

		waitDeleteNode->next = sonNode->next;
		delete(sonNode);
		sonNode = 0;		
	}
	//如果链表只有一个节点，删除头结点，也是尾节点
	else if (mNode == waitDeleteNode)
	{
		delete mNode;
		mNode = NULL;
	}
	else //如果链表有多个结点，需要删除的也是尾节点，特殊处理
	{
		DeleteNode(mNode, waitDeleteNode);
	}


	Node* DebugNode = mNode;
	while (DebugNode != NULL)
	{
		cout << "tNode" << DebugNode->value << endl;
		DebugNode = DebugNode->next;

	}

	return true;

}

//删除链表中的指定结点
bool NodeClass::DeleteNode(Node* mNode, Node* waitDeleteNode)
{
	//TODO:不能随便指，内存泄露
	Node* pNode =  mNode;
	Node* TempNode = NULL;
	Node* WaitNode = NULL;

	while (pNode != NULL)
	{
		TempNode = pNode;

		pNode = pNode->next;
		if (pNode!= NULL && pNode->value == waitDeleteNode->value)
		{
			TempNode->next = pNode->next;
			//delete 只是删除了指针指向的内存，并没有删除指针本身
			delete(pNode);
		}
		pNode = TempNode->next;
	}

	Node* DebugNode = mNode;


	while (DebugNode !=NULL)
	{
		cout << "tNode"<< DebugNode->value<<endl;
		DebugNode = DebugNode->next;

	}

	return true;

}