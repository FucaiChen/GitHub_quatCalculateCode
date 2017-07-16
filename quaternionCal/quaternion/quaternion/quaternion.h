#include <math.h>
template <class T>
class Quanternion
{
public:
	Quanternion();			//默认构造函数
	Quanternion(T quat0,T quat1,T quat2,T quat3); //构造函数
	Quanternion(Quanternion &Q);			//拷贝构造函数
	Quanternion(T* Q);						//构造函数
	Quanternion quatMultiply(Quanternion Q);			//叉乘另一个四元数
	Quanternion quatConj();											//取共轭
	Quanternion quatUnit();										//单位化
	Quanternion quatInverse();									//四元数求逆
protected:
private:
	T q0;
	T q1;
	T q2;
	T q3;
};
template <class T>
Quanternion<T>::Quanternion()
{
	this->q0=1;
	this->q1=0;
	this->q2=0;
	this->q3=0;
}
template <class T>
Quanternion<T>::Quanternion(T quat0,T quat1,T quat2,T quat3)   //构造函数
{
	this->q0=quat0;
	this->q1=quat1;
	this->q2=quat2;
	this->q3=quat3;
}
template<class T>
Quanternion<T>::Quanternion(Quanternion &Q)   //拷贝构造函数
{
	this->q0=Q.q0;
	this->q1=Q.q1;
	this->q2=Q.q2;
	this->q3=Q.q3;
}
template<class T>
Quanternion<T>::Quanternion(T* Q)   //拷贝构造函数
{
	this->q0=Q[0];
	this->q1=Q[1];
	this->q2=Q[2];
	this->q3=Q[3];
}

template <class T>
Quanternion<T> Quanternion<T>::quatMultiply(Quanternion Q)     
{
	Quanternion result(0,0,0,0);
	result.q0=this->q0*Q.q0-this->q1*Q.q1-this->q2*Q.q2-this->q3*Q.q3;
	result.q1=this->q0*Q.q1+this->q1*Q.q0+this->q2*Q.q3-this->q3*Q.q2;
	result.q2=this->q0*Q.q2-this->q1*Q.q3+this->q2*Q.q0+this->q3*Q.q1;
	result.q3=this->q0*Q.q3+this->q1*Q.q2-this->q2*Q.q1+this->q3*Q.q0;
	return result;
}

template<class T>
Quanternion<T> Quanternion<T>::quatConj()
{
	Quanternion Q(0,0,0,0);
	Q.q0=this->q0;
	Q.q1=-this->q1;
	Q.q2=-this->q2;
	Q.q3=-this->q3;
	return Q;
}
template<class T>
Quanternion<T> Quanternion<T>::quatUnit()
{
	Quanternion Q;
	T qNorm=sqrt(pow(this->q0,2)+pow(this->q1,2)+pow(this->q2,2)+pow(this->q3,2));
	Q.q0=this->q0/qNorm;
	Q.q1=this->q1/qNorm;
	Q.q2=this->q2/qNorm;
	Q.q3=this->q3/qNorm;
	return Q;
}

template <class T>
Quanternion<T> Quanternion<T>::quatInverse()
{
	Quanternion result;
	result=this->quatConj();
	T qNorm=sqrt(pow(this->q0,2)+pow(this->q1,2)+pow(this->q2,2)+pow(this->q3,2));
	result.q0=this->q0/qNorm;
	result.q1=this->q1/qNorm;
	result.q2=this->q2/qNorm;
	result.q3=this->q3/qNorm;
	return result;
}