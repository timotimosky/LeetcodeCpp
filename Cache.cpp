#include "stdafx.h"
#include "Cache.h"


Cache::Cache(int cache_size = 10)
{
}


Cache::~Cache()
{
}

int Cache::get(int key)
{
	CacheNode *p = p_cache_list_head->next;
	while (p->next != NULL)
	{
		if (p->key == key) //catch node  
		{
			detachNode(p);
			addToFront(p);

			//��¼ʹ�ô���
			p->UseNum++;
			return p->value;
		}
		p = p->next;
	}
	return -1;
}

//����ָ��
void Cache::detachNode(CacheNode *node)
{
	node->pre->next = node->next;
	node->next->pre = node->pre;
}

void Cache::addToFront(CacheNode *node)
{
	node->next = p_cache_list_head->next;
	p_cache_list_head->next->pre = node;
	p_cache_list_head->next = node;
	node->pre = p_cache_list_head;
}



bool Cache::put(int key, int value)
{
	CacheNode *p = p_cache_list_head->next;
	while (p->next != NULL)
	{
		if (p->key == key) //catch node  
		{
			p->value = value;

			//���⴦���ˣ�����ǰ��
			get(key);
			return true;
		}
		p = p->next;
	}

	int waitUseNum = 0;

	if (cache_real_size_ >= cache_size_)
	{
		p = p_cache_list_near->pre->pre;

		//����洢�����ݸ����������趨ֵ������Ƶ��ʹ�õ�����ɾ����Ȼ�������ֵ�����ͬʱ���ڼ������ʹ�ô��������ݣ�
		//���ǵ�ʹ�ô�����ͬ����������ʹ�õ�����ɾ����
		waitUseNum = p->next->UseNum;
		if (waitUseNum == 0)
		{
			delete p->next;
			p->next = p_cache_list_near;
			p_cache_list_near->pre = p;
		}
		else
		{
			bool deleteSucell;

			while (true)
			{
				waitUseNum = p->next->UseNum;
				if (p->UseNum >= waitUseNum)
				{
					_Node_* Next = p->next->next;
					delete p->next;
					p->next = Next;
					Next->pre = p;
					break;
				}

				p = p->pre;
				if (p == p_cache_list_head) 
				{
					p = p_cache_list_near->pre->pre;
					delete p->next;
					p->next = p_cache_list_near;
					p_cache_list_near->pre = p;
					break;
				}

			}
			
		}
	}

	p = new CacheNode();

	if (p == NULL)
		return false;

	//����ǰ��
	addToFront(p);
	p->key = key;
	p->value = value;
	p->UseNum = 0;

	cache_real_size_++;

	return true;
}


void Cache::displayNodes()
{
	CacheNode *p = p_cache_list_head->next;

	while (p->next != NULL)
	{
		p = p->next;
	}

}