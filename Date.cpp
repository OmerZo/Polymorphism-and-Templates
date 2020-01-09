#include "Date.h"


Date::Date(int d, int m, int y)
{
	this->day = d;
	this->month = m;
	this->year = y;
}


void Date::getDateFromString(string str, int& d, int& m, int& y)
{
	d = m = y = 0;
	int flag = 0;
	bool flagMinus = false;

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
		{

			switch (flag)
			{
			case 0:
			{
				if (flagMinus) d *= -1;
				break;
			}
			case 1:
			{
				if (flagMinus) m *= -1;
				break;
			}
			case 2:
			{
				if (flagMinus) y *= -1;
				break;
			}
			default:
				break;
			}


			flag++;
			flagMinus = false;
		}
		else if (str[i] == '-')
			flagMinus = true;
	}
	if (flagMinus) y *= -1;
}

void Date::checkDate(int d, int m, int y) const
{
	bool isLeapYear = (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));

	if ((d < 1) || (d > 31)) throw ILLEGAL_DAY;
	if ((m < 1) || (m > 12)) throw ILLEGAL_MONTH;
	if (y < 1) throw ILLEGAL_YEAR;

	if (isLeapYear && m == 2 && d > 29) throw NOT_LEAP;
	if (!isLeapYear && m == 2 && d > 28) throw NOT_LEAP;

	if ((m == 4 || m == 6 || m == 9 || m == 11) && (d > 30)) throw ILLEGAL_DAY;
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
	const Date* temp = dynamic_cast<const Date*>(&other);

	if (this->year != temp->year)
		return this->year < temp->year;
	else if (this->month != temp->month)
		return this->month < temp->month;
	else
		return this->day < temp->day;
}

bool Date::operator > (const IComparable<Date>& other) const
{
	return !((this->operator==(other)) || (this->operator<(other)));
}

bool Date::operator <= (const IComparable<Date>& other) const
{
	return ((this->operator==(other)) || (this->operator<(other)));

}

bool Date::operator >= (const IComparable<Date>& other) const
{
	return ((this->operator==(other)) || (this->operator>(other)));
}

bool Date::operator != (const IComparable<Date>& other) const
{
	return !(this->operator==(other));
}

bool Date::operator == (const IComparable<Date>& other) const
{
	const Date* temp = dynamic_cast<const Date*>(&other);
	return ((this->day == temp->day) && (this->month == temp->month) && (this->year == temp->year));
}


ostream& operator<<(ostream& os, const Date& date)
{
	try
	{
		date.checkDate(date.getDay(), date.getMonth(), date.getYear());
	}
	catch (FalutCode e)
	{
		switch (e)
		{
		case ILLEGAL_DAY:
		{
			cout << "Illegal day for month";
			return os;
		}
		case ILLEGAL_MONTH:
		{
			cout << "Illegal month";
			return os;
		}
		case ILLEGAL_YEAR:
		{
			cout << "Illegal year";
			return os;
		}
		case NOT_LEAP:
		{
			cout << "Not a leap year";
			return os;
		}
		default:
			break;
		}
	}

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

	date.setDay(d);
	date.setMonth(m);
	date.setYear(y);
	return in;
}