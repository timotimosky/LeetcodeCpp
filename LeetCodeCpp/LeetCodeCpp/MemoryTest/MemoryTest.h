#pragma once

//�ڴ����
class MemoryTest
{

	//�򵥵��ڴ����

	void TestPtrDelete()
	{
		ListNodeClass* mListNodeClass;  //������ʱ��Ϊ 0xcccccccc

		mListNodeClass = new ListNodeClass;  //����󣬷����ڴ�Ϊ0x01049ef8����ڴ��Ǹ�������仯��

		delete mListNodeClass; //ɾ����ֻ��ɾ��ָ��ָ��ĵ�ַ�����ݣ�����û��ɾ��ָ��ָ��ĵ�ַ ���ԣ����ڻ���0x01049ef8

		//�������ǻ�Ҫ�ÿա� ��ΪNULL���ڴ�Ϊ 0x00000000
		mListNodeClass = NULL;
	}


	//����ָ���ڴ����
	void TestPtr()
	{
		////C11��std 
		//shared_ptr<string> pbr;
		//unique_ptr<string> pbr;
		//weak_ptr<string> pbr;

		/*---------��ָ��------------*/
		shared_ptr<string> p1;
		if (!p1)//!Ĭ�ϳ�ʼ��������ָ���б�����һ����ָ�룡������""���ַ���
			cout << "p1==NULL" << endl;

		/*---------��ʼ��------------*///����Ҫע���ʱemptyʱ����string�ĳ�Ա������
		shared_ptr<string> p2(new string);
		if (p2 && p2->empty()) {
			*p2 = "helloworld";
			cout << *p2 << endl;
		}
		//    shared_ptr<int> pa = new int(1);//��error:�������Ա�¶��©��ָ����и�ֵ������

		  //һ��ĳ�ʼ����ʽ
		shared_ptr<string> pint(new string("normal usage!"));
		cout << *pint << endl;

		//�Ƽ��İ�ȫ�ĳ�ʼ����ʽ
		shared_ptr<string> pint1 = make_shared<string>("safe uage!");
		cout << *pint1 << endl;
		//pint1->r
	}

	//�������ü����Զ��ͷ�
	void TestReference()
	{
		auto p = make_shared<int>(42); //!ָ��Ķ���ֻ��pһ�������ߡ�
		cout << p.use_count() << endl;
		auto q = make_shared<int>(56);//!ָ��Ķ���ֻ��qһ�������ߡ�
		cout << q.use_count() << endl;

		cout << "---------afterAssin-----" << endl;
		p = q;                        //!pԭ�����õĶ��󾭹���ֵ֮���ͷŵ��ˣ�q���õĶ�������p��q�������á�
		cout << *p << "==" << *q << endl;
		cout << q.use_count() << endl;
		cout << p.use_count() << endl;
	}
	//���ǿ�����reset��һ�� �µ�ָ�븳��һ��shared_ptr��

	void TestReset()
	{
		shared_ptr<string> p1(new string("helloworld--1"));
		//    p1 = new string("helloworld2--2");//error!
		p1.reset(new string("helloworld2--2"));
		cout << *p1 << endl;
	}
	//�븳ֵ���ƣ�reset����£� - 1�����ü����������Ҫ�Ļ������ͷ�p1ָ��Ķ���reset��Ա������uniqueһ��ʹ�ã�
	//�����ƶ��shared_ptr�Ĺ�������ڸı�ײ����֮ǰ�������ڼ���Լ��Ƿ��ǵ�ǰ������е��û���
	//������ǣ��ڸı�֮ǰҪ��һ���µĿ�����

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

