#ifndef INTERVAL_H
#define INTERVAL_H
#include <iostream>
#include "IComparable.h"
#include "IPrintable.h"

using namespace std;

template <class T>
class Interval: public IComparable<T> , public IPrintable
{
public:

	Interval<T>(T, T);

	virtual void output(const IPrintable&);
	virtual void input(IPrintable&);
	
	virtual bool operator < (const IComparable<T>&) const;
	virtual bool operator > (const IComparable<T>&) const;
	virtual bool operator <= (const IComparable<T>&) const;
	virtual bool operator >= (const IComparable<T>&) const;
	virtual bool operator != (const IComparable<T>&) const;
	virtual bool operator == (const IComparable<T>&) const;

	friend ostream& operator << (ostream& os, const Interval& inter)
	{
		cout << "ostream inline" << endl;
		os << inter.x << ", " << inter.y << endl;
		return os;
	}


	friend istream& operator >> (istream& in, Interval<T>& inter)
	{
		cout << "istream inline";
		return in;
	}

private:
	T x, y;
};

#endif // !INTERVAL_H


template <class T>
Interval<T>::Interval(T x, T y)
{
	cout << x << ", " << y << endl;
	this->x = x;
	this->y = y;
}

template<class T>
void Interval<T>::output(const IPrintable& inter)
{
	const Interval<T>* temp = dynamic_cast<const Interval<T>*>(&inter);
	cout << "test1";
	//cout << temp;
}

template<class T>
void Interval<T>::input(IPrintable& inter)
{
}

template<class T>
bool Interval<T>::operator<(const IComparable<T>& other) const
{
	return false;
}

template<class T>
bool Interval<T>::operator>(const IComparable<T>& other) const
{
	return false;
}

template<class T>
bool Interval<T>::operator<=(const IComparable<T>& other) const
{
	return false;
}

template<class T>
bool Interval<T>::operator>=(const IComparable<T>& other) const
{
	return false;
}

template<class T>
bool Interval<T>::operator!=(const IComparable<T>& other) const
{
	return false;
}

template<class T>
bool Interval<T>::operator==(const IComparable<T>& other) const
{
	return false;
}

//template<class T>
//ostream& operator << (ostream& os, const Interval<T>& interval)
//{
//	cout << "test1";
//	//os << interval.x << ", " << interval.y << endl;
//	return os;
//}
//
//template <class T>
//istream& operator >> (istream& in, Interval<T>& interval)
//{
//	return in;
//}
