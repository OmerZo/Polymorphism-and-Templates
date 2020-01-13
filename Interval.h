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

	Interval<T> operator && (const Interval<T>&) const;
	Interval<T> operator || (const Interval<T>&) const;

	bool isEmpty() const;
	bool isBefore(const Interval<T>&) const;
	bool isAfter(const Interval<T>&) const;
	bool intersects(const Interval<T>&) const;
	bool contains(T) const;

	friend ostream& operator << (ostream& os, const Interval& inter)
	{
		if (inter.start > inter.end)
			os << "Invalid interval";
		else if (inter.start == inter.end)
			os << "EMPTY";
		else 
			os << "(" << inter.start << ", " << inter.end << ")";
		return os;
	}

	friend istream& operator >> (istream& in, Interval<T>& inter)
	{
		cout << "istream inline";
		return in;
	}

private:
	T start, end;
};

#endif // !INTERVAL_H


template <class T>
Interval<T>::Interval(T start, T end)
{
	this->start = start;
	this->end = end;
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
Interval<T> Interval<T>::operator&&(const Interval<T>& inter) const
{
	if(!this->intersects(inter))
		return Interval<T>(inter.start, inter.start);

	if (this->contains(inter.start) && this->contains(inter.end))
		return Interval<T>(this->start, this->end);

	if (inter.contains(this->start) && inter.contains(this->end))
		return Interval<T>(inter.start, inter.end);

	T start, end;
	if ((this->start > inter.start) && (this->start < inter.end))
	{
		start = this->start;
		end = inter.end;
	}
	else
	{
		start = inter.start;
		end = this->end;
	}
	return Interval<T>(start, end);
}

template<class T>
Interval<T> Interval<T>::operator||(const Interval<T>& inter) const
{
	if (!this->intersects(inter))
		return Interval<T>(inter.end, inter.start);
	
	T start, end;
	start = (this->start < inter.start) ? this->start : inter.start;
	end = (this->end > inter.end) ? this->end : inter.end;
	return Interval<T>(start, end);
}


template<class T>
bool Interval<T>::isEmpty() const
{
	return (this->start == this->end);
}

template<class T>
bool Interval<T>::isBefore(const Interval<T> &inter) const
{
	return (this->end <= inter.start);
}

template<class T>
bool Interval<T>::isAfter(const Interval<T> &inter) const
{
	return (inter.end <= this->start);
}

template<class T>
bool Interval<T>::intersects(const Interval<T>& inter) const
{
	return (((this->end > inter.start) && (this->end < inter.end)) || ((this->start > inter.start) && (this->start < inter.end)));
}

template<class T>
bool Interval<T>::contains(T cont) const
{
	return ((this->start < cont) && (this->end > cont));
}