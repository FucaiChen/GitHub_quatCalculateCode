#include "quaternionCal.h"
#include "StdAfx.h"
#include <math.h>
double* quatMultiply(double p[4],double q[4])  //四元数乘法
{
	double Qresult[4];
	Qresult[0]=p[0]*q[0]-p[1]*q[1]-p[2]*q[2]-p[3]*q[3];
	Qresult[1]=p[0]*q[1]+p[1]*q[0]+p[2]*q[3]-p[3]*q[2];
	Qresult[2]=p[0]*q[2]+p[2]*q[0]+p[3]*q[1]-p[1]*q[3];
	Qresult[3]=p[0]*q[3]+p[3]*q[0]+p[1]*q[2]-p[2]*q[1];
	return Qresult;
}

double* quatPlus(double p[4],double q[4])  //四元数加法
{
	double Qresult[4];
	Qresult[0]=p[0]+q[0];
	Qresult[1]=p[1]+q[1];
	Qresult[2]=p[2]+q[2];
	Qresult[3]=p[3]+q[3];
	return Qresult;
}

double* quatConj(double p[4])   //共轭
{
	double Qresult[4];
	Qresult[0]=p[0];
	Qresult[1]=-p[1];
	Qresult[2]=-p[2];
	Qresult[3]=-p[3];
	return Qresult;
}

double* quatUnit(double p[4])   //四元数单位化
{
	double Qresult[4];
	double Qnorm=sqrt(pow(p[0],2)+pow(p[1],2)+pow(p[2],2)+pow(p[3],2));
	Qresult[0]=p[0]/Qnorm;
	Qresult[1]=-p[1]/Qnorm;
	Qresult[2]=-p[2]/Qnorm;
	Qresult[3]=-p[3]/Qnorm;
	return Qresult;
}

//template <class T>
//class Quanternion
//{
//public:
//	Quanternion(T quat0,T quat1,T quat2,T quat3); //构造函数
//	Quanternion(Quanternion &Q);			//拷贝构造函数
//	Quanternion(T* Q);						//构造函数
//protected:
//private:
//	T q0;
//	T q1;
//	T q2;
//	T q3;
//};
