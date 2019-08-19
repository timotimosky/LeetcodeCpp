#pragma once



//1.单向链表中删除链表节点，O（1）时间内

//由于头结点可能被删除，链表最好创建一个独立的头结点

//尾节点倒
struct Node
{
	int value;

	Node* next;

	Node(int x)
	{
		value = x;
		next = nullptr;
	}
};


class NodeClass
{
public:
	NodeClass();
	~NodeClass();

	bool DeleteNode(Node* mNode, Node* waitDeleteNode);
	bool DeleteNodeO1(Node* mNode, Node* waitDeleteNode);
};

