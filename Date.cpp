#include "Date.h"


Date::Date(int d, int m, int y)
{
	cout << "Date conc d=" << d << " m=" << m << " y=" << y << endl;
	this->day = d;
	this->month = m;
	this->year = y;
}

bool Date::operator < (const Date& other) const
{
	cout << "Date::operator <" << endl;
	cout << "this->day=" << this->day << endl;
	cout << "other.day=" << other.day<< endl;
	return true;
}

bool Date::operator > (const Date& other) const
{
	cout << "Date::operator >" << endl;
	cout << "this->day=" << this->day << endl;
	cout << "other.day=" << other.day << endl;
	return true;
}

bool Date::operator <= (const Date& other) const
{
	cout << "Date::operator <=" << endl;
	cout << "this->day=" << this->day << endl;
	cout << "other.day=" << other.day << endl;
	return true;
}

bool Date::operator >= (const Date& other) const
{
	cout << "Date::operator >=" << endl;
	cout << "this->day=" << this->day << endl;
	cout << "other.day=" << other.day << endl;
	return true;
}

bool Date::operator != (const Date& other) const
{
	cout << "Date::operator !=" << endl;
	cout << "this->day=" << this->day << endl;
	cout << "other.day=" << other.day << endl;
	return true;
}

bool Date::operator == (const Date& other) const
{
	cout << "Date::operator ==" << endl;
	cout << "this->day=" << this->day << endl;
	cout << "other.day=" << other.day << endl;
	return true;
}