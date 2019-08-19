#pragma once
class CacheClass
{
public:
	CacheClass();
	~CacheClass();
};
class Cache
{

	Cache(int cache_size = 10);  //构造函数，默认cache大小为10  
	~Cache(); //析构函数  


	int get(int key);   //获取值
	bool put(int key, int value);  //写入或更新值   
	void displayNodes();   //辅助函数，显示所有节点  


private:

	int cache_size_;                   //cache长度  
	int cache_real_size_;              //目前使用的长度  
	CacheNode *p_cache_list_head;      //头节点指针  
	CacheNode *p_cache_list_near;      //尾节点指针  

	void detachNode(CacheNode *node);  //分离节点  
	void addToFront(CacheNode *node);  //将节点插入到第一个  
};
