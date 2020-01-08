#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H

template <class T>
class IComparable
{
public:

	virtual ~IComparable() {};
	virtual bool operator < (const IComparable&) const = 0;
	virtual bool operator > (const IComparable&) const = 0;
	virtual bool operator <= (const IComparable&) const = 0;
	virtual bool operator >= (const IComparable&) const = 0;
	virtual bool operator != (const IComparable&) const = 0;
	virtual bool operator == (const IComparable&) const = 0;
};

#endif // !ICOMPARABLE_H
