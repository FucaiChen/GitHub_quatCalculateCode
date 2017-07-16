// quaternion.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
//#include "quaternionCal.h"
#include "quaternion.h"
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	//double p[4]={0.8660,0.5,0,0};
	//double q[4]={0.7071,0.7071,0.7071,0.7071};
	//double* c;
	//c=quatMultiply(p,q);
	//cout<<*c<<endl<<*(c+1)<<endl<<*(c+2)<<endl<<*(c+3)<<endl;
	//c=quatPlus(p,q);
	//cout<<*c<<endl<<*(c+1)<<endl<<*(c+2)<<endl<<*(c+3)<<endl;
	Quanternion<double> a(0.999,0.01,0,0);
	Quanternion<double> b(a.quatConj());
	Quanternion<double> c(a.quatMultiply(b));
	return 0;
}

