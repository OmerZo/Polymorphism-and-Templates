#include "Date.h"


Date::Date(int d, int m, int y)
{
	cout << "Date conc d=" << d << " m=" << m << " y=" << y << endl;
	this->day = d;
	this->month = m;
	this->year = y;
}

void Date::getDateFromString(string str, int& d, int& m, int& y)
{
	d = m = y = 0;
	int flag = 0;

	for (int i = 0; i < (int)str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			switch (flag)
			{
			case 0:
			{
				d *= 10;
				d += (str[i] - '0');
				break;
			}
			case 1:
			{
				m *= 10;
				m += (str[i] - '0');
				break;
			}
			case 2:
			{
				y *= 10;
				y += (str[i] - '0');
				break;
			}
			default:
				break;
			}
		}
		else if (str[i] == '/')
			flag++;
	}
}

bool Date::isLeapYear(int year)
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}


void Date::setDate(int d, int m, int y)
{
	this->setDay(d);
	this->setMonth(m);
	this->setYear(y);
}

void Date::setDay(int d)
{
	this->day = d;
}

void Date::setMonth(int m)
{
	this->month = m;
}

void Date::setYear(int y)
{
	this->year = y;
}


int Date::getDay() const
{
	return this->day;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getYear() const
{
	return this->year;
}


void Date::output(const IPrintable& date)
{
	const Date* temp = dynamic_cast<const Date*>(&date);
	cout << temp;
}

void Date::input(IPrintable& date)
{
	const Date* temp = dynamic_cast<const Date*>(&date);
	cout << temp;
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


ostream& operator<<(ostream& os, const Date& date)
{
	(date.day < 10) ? (os << "0" << date.day) : (os << date.day);
	os << "/";
	(date.month < 10) ? (os << "0" << date.month) : (os << date.month);
	os << "/";
	os << date.year;
	return os;
}

istream& operator>>(istream& in, Date& date)
{
	string str;
	int d, m, y;

	getline(in, str);
	date.getDateFromString(str, d, m, y);
	date.isLeapYear(y) ? date.setDate(d, m, y) : date.setDate(1,1,1);
	return in;
}
