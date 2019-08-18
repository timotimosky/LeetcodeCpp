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

			//记录使用次数
			p->UseNum++;
			return p->value;
		}
		p = p->next;
	}
	return -1;
}

//重新指向
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

			//特殊处理了，排序到前面
			get(key);
			return true;
		}
		p = p->next;
	}

	int waitUseNum = 0;

	if (cache_real_size_ >= cache_size_)
	{
		p = p_cache_list_near->pre->pre;

		//如果存储的数据个数超过了设定值，请把最不频繁使用的数据删除，然后存入新值。如果同时存在几个最低使用次数的数据，
		//它们的使用次数相同，请把最近不使用的数据删除。
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

	//排序到前面
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