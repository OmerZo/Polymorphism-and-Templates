#ifndef INTERVAL_H
#define INTERVAL_H
#include <iostream>
#include "IComparable.h"
#include "IPrintable.h"
#include <string>

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

	string operator && (const Interval<T>&) const;
	string operator || (const Interval<T>&) const;

	bool isEmpty() const;
	bool isBefore(const Interval<T>&) const;
	bool isAfter(const Interval<T>&) const;
	bool intersects(const Interval<T>&) const;

	friend ostream& operator << (ostream& os, const Interval& inter)
	{
		if (inter.x > inter.y)
			os << "Invalid interval";
		else
			os << "(" << inter.x << ", " << inter.y << ")";
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

template<class T>
string Interval<T>::operator&&(const Interval<T>& inter) const
{
	if(!this->intersects(inter))
		return "EMPTY";

	//if (this.contain(inter))
		//return "(" + this->x + ", " + this->y + ")";

	//if (inter.contain(this))
		//return "(" + inter.x + ", " + inter.y + ")";

	T x, y;
	if ((this->x > inter.x) && (this->x < inter.y))
	{
		x = this->x;
		y = inter.y;
	}
	else
	{
		x = inter.x;
		y = this->y;
	}
	//return "(" + x + ", " + y + ")";
	return x y;
}

template<class T>
string Interval<T>::operator||(const Interval<T>& inter) const
{
	return "operator||";
}


template<class T>
bool Interval<T>::isEmpty() const
{
	return (this->x == this->y);
}

template<class T>
bool Interval<T>::isBefore(const Interval<T> &inter) const
{
	return (this->y <= inter.x);
}

template<class T>
bool Interval<T>::isAfter(const Interval<T> &inter) const
{
	return (inter.y <= this->x);
}

template<class T>
bool Interval<T>::intersects(const Interval<T>& inter) const
{
	return (((this->y > inter.x) && (this->y < inter.y)) || ((this->x > inter.x) && (this->x < inter.y)));
}