#ifndef DATE_H
#define DATE_H
#include <iostream>
#include "IComparable.h"
#include "IPrintable.h"
#include <string>

using namespace std;

enum FalutCode { ILLEGAL_DAY = 1, ILLEGAL_MONTH, ILLEGAL_YEAR, NOT_LEAP };

class Date : public IComparable<Date>, public IPrintable
{
public:

	Date(int, int, int);

	void getDateFromString(string, int&, int&, int&);

	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void checkDate(int, int, int) const;

	int getDay() const;
	int getMonth() const;
	int getYear() const;

	virtual void output(const IPrintable&);
	virtual void input(IPrintable&);

	virtual bool operator < (const IComparable<Date>&) const;
	virtual bool operator > (const IComparable<Date>&) const;
	virtual bool operator <= (const IComparable<Date>&) const;
	virtual bool operator >= (const IComparable<Date>&) const;
	virtual bool operator != (const IComparable<Date>&) const;
	virtual bool operator == (const IComparable<Date>&) const;

	friend ostream& operator << (ostream&, const Date&);
	friend istream& operator >> (istream&, Date&);

private:
	int day, month, year;
};


#endif // !DATE_H
