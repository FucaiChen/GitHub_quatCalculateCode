// quaternion.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "quaternionCal.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	double p[4]={0.8660,0.5,0,0};
	double q[4]={0.7071,0.7071,0.7071,0.7071};
	double* c;
	c=quatMultiply(p,q);
	cout<<*c<<endl<<*(c+1)<<endl<<*(c+2)<<endl<<*(c+3);
	return 0;
}

