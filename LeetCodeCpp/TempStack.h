#pragma once

//statck.h
template <class T> class Stack {
public:
	Stack();
	~Stack();
	void push(T t);
	T pop();
	bool isEmpty();
private:
	T* m_pT;
	int m_maxSize;
	int m_size;
};

#include "TempStack.cpp"


//模板跟普通类不同   
//模板有个具现化的过程，在未被使用的时候是不会生成二进制文件的。所以当链接器去找f函数的地址时，
//因为在这之前没有调用过f()，TempStack.obj里自然就没有f函数的二进制代码，于是就会报错。
//如果要把CPP文件跟H文件分离开，那么其他类调用的时候 要#include "TempStack.cpp" 而不是传统的
//#include "TempStack.h"
//因为会导致重复引用 "TempStack.h"

//stack.cpp
template <class  T>
Stack<T>::Stack() {
	m_maxSize = 100;
	m_size = 0;
	m_pT = new T[m_maxSize];
}
template <class T>
Stack<T>::~Stack() {
	delete[] m_pT;
}

//模板专门化： 比如我们处理某些元素输入时，考虑到实现或者性能需求不同，那么可以用模板专门化来重载
//template<>前缀表示这是一个专门化,描述时不用模板参数
//template<> void Add(int& t2) {
//	m_size++;
//	m_pT[m_size - 1] = t;
//}



template <class T>
void Stack<T>::push(T t) {
	m_size++;
	m_pT[m_size - 1] = t;

}
template <class T>
T Stack<T>::pop() {
	T t = m_pT[m_size - 1];
	m_size--;
	return t;
}
template <class T>
bool Stack<T>::isEmpty() {
	return m_size == 0;
}