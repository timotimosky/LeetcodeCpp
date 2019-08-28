#pragma once

//内存管理
class MemoryTest
{

	//简单的内存管理

	void TestPtrDelete()
	{
		ListNodeClass* mListNodeClass;  //声明的时候为 0xcccccccc

		mListNodeClass = new ListNodeClass;  //定义后，分配内存为0x01049ef8这个内存是根据情况变化的

		delete mListNodeClass; //删除后，只是删除指针指向的地址的内容，但是没有删除指针指向的地址 所以，现在还是0x01049ef8

		//所以我们还要置空。 置为NULL后，内存为 0x00000000
		mListNodeClass = NULL;
	}


	//智能指针内存管理
	void TestPtr()
	{
		////C11的std 
		//shared_ptr<string> pbr;
		//unique_ptr<string> pbr;
		//weak_ptr<string> pbr;

		/*---------空指针------------*/
		shared_ptr<string> p1;
		if (!p1)//!默认初始化的智能指针中保存着一个空指针！并不是""空字符串
			cout << "p1==NULL" << endl;

		/*---------初始化------------*///！需要注意的时empty时属于string的成员函数。
		shared_ptr<string> p2(new string);
		if (p2 && p2->empty()) {
			*p2 = "helloworld";
			cout << *p2 << endl;
		}
		//    shared_ptr<int> pa = new int(1);//！error:不允许以暴露裸漏的指针进行赋值操作。

		  //一般的初始化方式
		shared_ptr<string> pint(new string("normal usage!"));
		cout << *pint << endl;

		//推荐的安全的初始化方式
		shared_ptr<string> pint1 = make_shared<string>("safe uage!");
		cout << *pint1 << endl;
		//pint1->r
	}

	//测试引用技术自动释放
	void TestReference()
	{
		auto p = make_shared<int>(42); //!指向的对象只有p一个引用者。
		cout << p.use_count() << endl;
		auto q = make_shared<int>(56);//!指向的对象只有q一个引用者。
		cout << q.use_count() << endl;

		cout << "---------afterAssin-----" << endl;
		p = q;                        //!p原来引用的对象经过赋值之后释放掉了，q引用的对象有了p和q两个引用。
		cout << *p << "==" << *q << endl;
		cout << q.use_count() << endl;
		cout << p.use_count() << endl;
	}
	//我们可以用reset将一个 新的指针赋予一个shared_ptr：

	void TestReset()
	{
		shared_ptr<string> p1(new string("helloworld--1"));
		//    p1 = new string("helloworld2--2");//error!
		p1.reset(new string("helloworld2--2"));
		cout << *p1 << endl;
	}
	//与赋值类似，reset会更新（ - 1）引用计数，如果需要的话，会释放p1指向的对象。reset成员经常与unique一起使用，
	//来控制多个shared_ptr的共享对象。在改变底层对象之前，我们在检查自己是否是当前对象仅有的用户。
	//如果不是，在改变之前要做一份新的拷贝：

	void TestReset2()
	{
		shared_ptr<string> p1(new string("helloworld--1"));
		shared_ptr<string> p2(p1);

		if (p1.unique())
			cout << *p1 + string(" is unique!") << endl;
		else {
			cout << p2.use_count() << "reference" << endl;
			p1.reset(new string("new reset!"));
			cout << *p1 << endl;
			cout << p2.use_count() << "reference" << endl;
		}
	}
};

