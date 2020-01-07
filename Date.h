#ifndef DATE_H
#define DATE_H
#include "IComparable.h"

class Date : public IComparable<Date>
{
public:
	Date();
	Date(int, int, int);

private:
	int day, month, year;
};


#endif // !DATE_H
