#pragma once



//1.����������ɾ������ڵ㣬O��1��ʱ����

//����ͷ�����ܱ�ɾ����������ô���һ��������ͷ���

//β�ڵ㵹
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

