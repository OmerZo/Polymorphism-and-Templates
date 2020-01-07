#ifndef IComparable
#define IComparable

template <class T>
class IComparable
{
pablic:
	virtual ~IComparable() {};
	virtual bool operator<(const IComparable&) const = 0;
	virtual bool operator>(const IComparable&) const = 0;
	virtual bool operator<=(const IComparable&) const = 0;
	virtual bool operator>=(const IComparable&) const = 0;
	virtual bool operator!=(const IComparable&) const = 0;
	virtual bool operator==(const IComparable&) const = 0;


};

#endif // !IComparable