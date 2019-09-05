#pragma once
#include "OperaterReload.h"

int TestOperater()
{
	String_OperaterReload str1(1, "hhxx");
	cout << "====================" << endl;
	String_OperaterReload str2;
	str2 = str1;
	cout << "====================" << endl;
	String_OperaterReload str3 = str2;
	return 0;
}

