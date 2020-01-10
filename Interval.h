#ifndef INTERVAL_H
#define INTERVAL_H
#include "IComparable.h"
#include "IPrintable.h"

template <class T>
class Interval: public IComparable<T> , IPrintable
{
public:

	Interval(T, T);

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