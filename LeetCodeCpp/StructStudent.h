#pragma once

//�����ṹ�����͵�λ��һ�����ļ��Ŀ�ͷ�������к���������main������֮ǰ��
//�Ա㱾�ļ������еĺ��������������������������ȻҲ�����ں����������ṹ�����͡�
//��C�����У��ṹ��ĳ�Աֻ�������ݣ�����������������ʾ����������
//C++�Դ˼������䣬�ṹ��ĳ�Ա�ȿ��԰������ݣ������ݳ�Ա�����ֿ��԰�����������������Ա��������Ӧ�������ĳ�����ơ�


//1 ��������һ���ṹ������Student �������������ڴ�
struct Student
{
	//ÿһ����ԱҲ��Ϊ�ṹ���е�һ����(field)����Ա�����ֳ�Ϊ���
	int num;  //����һ�����ͱ���num
	char name[20];  //����һ���ַ�����name����������20���ַ�
	char sex;  //����һ���ַ�����sex
	int age;   //����һ�����ͱ���age
	float score;   //����һ���������ͱ���
	char addr[30];  //����һ���ַ�����addr����������30���ַ�
};  //�����һ���ֺ�


//2 ���������͵�ͬʱ������� ���ʺϵ��ṹ��ֻ���ڱ��ļ�
struct NStudent  //�����ṹ������Student
{
	int num;
	char name[20];
	char sex;
	int age;
	float score;
	char addr[30];
}student5, student6;  //���������ṹ������Student�ı���student1��student2

//3) ֱ�Ӷ���ṹ�����ͱ�����
struct 
{
	int num;
	char name[20];
}student7, student8;  

//4. ���������͵�ͬʱ������� ���ҳ�ʼ������
struct IStudent
{
	int num;
	char name[20];
	char sex;
	int age;
	float score;
	char addr[30];
}student9 = { 10001, "Zhang Xin", 'M', 19, 90.5, "Shanghai" };

class StructStudent
{

	//�����˽ṹ�������ϵͳ��Ϊ֮�����ڴ浥Ԫ������student1��student2���ڴ��и�ռ63���ֽ�(4+20+1+4+4+30=63)��
	//C
	struct Student  Student3;
	//C++
	Student Student1��Student2;

	//��ʼ��
	void Init()
	{
		Student student2 = { 10002, "Wang Li", 20, 98,33, "Beijing" };
	}
};

