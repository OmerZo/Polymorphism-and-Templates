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
	cout << "Date < this: d=" << this->day << " m=" << this->month << " y=" << this->year << endl;
	//cout << "Date < d=" << d << " m=" << m << " y=" << y << endl;


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
	const Date* temp = dynamic_cast<const Date*>(&other);
	cout << "this->day=" << this->day << endl;
	cout << "dynamic_cast<Date*>(const &other)->day=" << dynamic_cast<const Date*>(&other)->day << endl;
	
	return temp < this;
}

bool Date::operator <= (const IComparable<Date>& other) const
{
	cout << "Date::operator <=" << endl;
	cout << "this->day=" << this->day << endl;
	cout << "dynamic_cast<Date*>(const &other)->day=" << dynamic_cast<const Date*>(&other)->day << endl;
	return true;
}

bool Date::operator >= (const IComparable<Date>& other) const
{
	cout << "Date::operator >=" << endl;
	cout << "this->day=" << this->day << endl;
	cout << "dynamic_cast<Date*>(const &other)->day=" << dynamic_cast<const Date*>(&other)->day << endl;
	return true;
}

bool Date::operator != (const IComparable<Date>& other) const
{
	cout << "Date::operator !=" << endl;
	cout << "this->day=" << this->day << endl;
	cout << "dynamic_cast<Date*>(const &other)->day=" << dynamic_cast<const Date*>(&other)->day << endl;
	return true;
}

bool Date::operator == (const IComparable<Date>& other) const
{
	cout << "Date::operator ==" << endl;
	cout << "this->day=" << this->day << endl;
	cout << "dynamic_cast<Date*>(const &other)->day=" << dynamic_cast<const Date*>(&other)->day << endl;
	return true;
}