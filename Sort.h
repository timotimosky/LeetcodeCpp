#pragma once


//直接插入排序
class Sort
{
public:
	Sort();
	~Sort();

	void print(int a[], int n, int i);

	void InsertSort(int a[], int n);

	void ShellSort();

	void QuickSort(int a[], int n);


	void BubbleSort(int a[], int n);

	void Test();




	//拷贝构造函数的参数为什么必须是const引用？

	//1  在调用拷贝构造函数的时候  CExample B(A);
	//上面 B(A) 中实参 A  赋给形参 C（CExample(const CExample C)） 的时候，本身就要触发拷贝构造函数 C(A) ，这个 C(A)  中的 A 又要赋给形参 C'.......
	//这是不是要无限次的进行拷贝？
	//所以，如果使用引用就可以避免这样的无限循环。

	//2 那为什么要用const引用？
	//const 更多是给程序员的一个限制， 告诉程序员这个变量是只读的。因此为了安全， 一般建议所有的只读变量加const限制以防止程序员犯错。
	//因为复制构造函数是用引用方式传递复制对象，引用方式传递的是地址，因此在构造函数内对该引用的修改会影响源对象。
	//而你在用对象a1构造a2时，自然不希望复制构造函数会改变a1的内容，因此要防止复制构造函数内部修改该引用，所以用const声明。
	Sort(const Sort& input)
	{
		
	}
};

