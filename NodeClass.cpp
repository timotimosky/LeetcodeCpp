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



//˫������ɾ�����죬����Ϊ��ɾ����ʱ��ֱ���ұ�ɾ���ڵ�ĸ��ڵ�ָ��ɾ���ڵ���ӽڵ㡣
//��O(1)ʱ�䷶Χ��ɾ��Node�ڵ�
bool NodeClass::DeleteNodeO1(Node* mNode, Node* waitDeleteNode)
{

	if (!mNode || !waitDeleteNode)
		return false;


	Node* sonNode = waitDeleteNode->next;

	//���������β�ڵ�
	if (sonNode != NULL)
	{
		//�ҵ���һ���ڵ�
		waitDeleteNode->value = sonNode->value;

		waitDeleteNode->next = sonNode->next;
		delete(sonNode);
		sonNode = 0;		
	}
	//�������ֻ��һ���ڵ㣬ɾ��ͷ��㣬Ҳ��β�ڵ�
	else if (mNode == waitDeleteNode)
	{
		delete mNode;
		mNode = NULL;
	}
	else //��������ж����㣬��Ҫɾ����Ҳ��β�ڵ㣬���⴦��
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

//ɾ�������е�ָ�����
bool NodeClass::DeleteNode(Node* mNode, Node* waitDeleteNode)
{
	//TODO:�������ָ���ڴ�й¶
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
			//delete ֻ��ɾ����ָ��ָ����ڴ棬��û��ɾ��ָ�뱾��
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