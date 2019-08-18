#pragma once
class CacheClass
{
public:
	CacheClass();
	~CacheClass();
};
class Cache
{

	Cache(int cache_size = 10);  //���캯����Ĭ��cache��СΪ10  
	~Cache(); //��������  


	int get(int key);   //��ȡֵ
	bool put(int key, int value);  //д������ֵ   
	void displayNodes();   //������������ʾ���нڵ�  


private:

	int cache_size_;                   //cache����  
	int cache_real_size_;              //Ŀǰʹ�õĳ���  
	CacheNode *p_cache_list_head;      //ͷ�ڵ�ָ��  
	CacheNode *p_cache_list_near;      //β�ڵ�ָ��  

	void detachNode(CacheNode *node);  //����ڵ�  
	void addToFront(CacheNode *node);  //���ڵ���뵽��һ��  
};
