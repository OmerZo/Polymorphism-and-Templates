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
