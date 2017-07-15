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
	double Qnorm=sqrt(pow(Qresult[0],2)+pow(Qresult[1],2)+pow(Qresult[2],2)+pow(Qresult[3],2));
	Qresult[0]=p[0]/Qnorm;
	Qresult[1]=-p[1]/Qnorm;
	Qresult[2]=-p[2]/Qnorm;
	Qresult[3]=-p[3]/Qnorm;
	return Qresult;
}