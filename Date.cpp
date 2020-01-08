#include "Date.h"


Date::Date(int d, int m, int y)
{
	cout << "Date conc d=" << d << " m=" << m << " y=" << y << endl;
	this->day = d;
	this->month = m;
	this->year = y;
}

bool Date::operator < (const IComparable<Date>& other) const
{
	cout << "Date::operator <" << endl;
	const Date* temp = dynamic_cast<const Date*>(&other);
	cout << "Date < d=" << temp->day << " m=" << temp->month << " y=" << temp->year << endl;

	if (this->year != temp->year)
		return this->year < temp->year;
	else if (this->month != temp->month)
		return this->month < temp->month;
	else
		return this->day < temp->day;
}

bool Date::operator > (const IComparable<Date>& other) const
{
	cout << "Date::operator >" << endl;
	return !((this->operator==(other)) || (this->operator<(other)));
}

bool Date::operator <= (const IComparable<Date>& other) const
{
	cout << "Date::operator <=" << endl;
	return ((this->operator==(other)) || (this->operator<(other)));

}

bool Date::operator >= (const IComparable<Date>& other) const
{
	cout << "Date::operator >=" << endl;
	return ((this->operator==(other)) || (this->operator>(other)));
}

bool Date::operator != (const IComparable<Date>& other) const
{
	cout << "Date::operator !=" << endl;
	return !(this->operator==(other));
}

bool Date::operator == (const IComparable<Date>& other) const
{
	cout << "Date::operator ==" << endl;
	const Date* temp = dynamic_cast<const Date*>(&other);
	return ((this->day == temp->day) && (this->month == temp->month) && (this->year == temp->year));
}