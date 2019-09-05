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


//ģ�����ͨ�಻ͬ   
//ģ���и����ֻ��Ĺ��̣���δ��ʹ�õ�ʱ���ǲ������ɶ������ļ��ġ����Ե�������ȥ��f�����ĵ�ַʱ��
//��Ϊ����֮ǰû�е��ù�f()��TempStack.obj����Ȼ��û��f�����Ķ����ƴ��룬���Ǿͻᱨ��
//���Ҫ��CPP�ļ���H�ļ����뿪����ô��������õ�ʱ�� Ҫ#include "TempStack.cpp" �����Ǵ�ͳ��
//#include "TempStack.h"
//��Ϊ�ᵼ���ظ����� "TempStack.h"

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

//ģ��ר�Ż��� �������Ǵ���ĳЩԪ������ʱ�����ǵ�ʵ�ֻ�����������ͬ����ô������ģ��ר�Ż�������
//template<>ǰ׺��ʾ����һ��ר�Ż�,����ʱ����ģ�����
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