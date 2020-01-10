#include "Interval.h"

template <class T>
Interval<T>::Interval(T x, T y)
{
	//this->x = x;
	//this->y = y;
}

template<class T>
void Interval<T>::output(const IPrintable&)
{
}

template<class T>
void Interval<T>::input(IPrintable&)
{
}

template<class T>
bool Interval<T>::operator<(const IComparable<T>&) const
{
	return false;
}

template<class T>
bool Interval<T>::operator>(const IComparable<T>&) const
{
	return false;
}

template<class T>
bool Interval<T>::operator<=(const IComparable<T>&) const
{
	return false;
}

template<class T>
bool Interval<T>::operator>=(const IComparable<T>&) const
{
	return false;
}

template<class T>
bool Interval<T>::operator!=(const IComparable<T>&) const
{
	return false;
}

template<class T>
bool Interval<T>::operator==(const IComparable<T>&) const
{
	return false;
}