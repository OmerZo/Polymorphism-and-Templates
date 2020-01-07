#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "IComparable.h"

using namespace std;

class Date : public IComparable<Date>
{
public:
	//virtual bool test(Date&);

	Date(int, int, int);
	virtual bool operator < (const IComparable<Date>&) const;
	virtual bool operator > (const IComparable<Date>&) const;
	virtual bool operator <= (const IComparable<Date>&) const;
	virtual bool operator >= (const IComparable<Date>&) const;
	virtual bool operator != (const IComparable<Date>&) const;
	virtual bool operator == (const IComparable<Date>&) const;


private:
	int day, month, year;
};


#endif // !DATE_H
