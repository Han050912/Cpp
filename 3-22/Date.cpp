#include"Date.h"

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	if (!(CheckDate()))
	{
		cout << "非法日期:";
		Print();
	}
}

bool Date::CheckDate() const
{
	if (_month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year, _month))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Date::Print() const
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

// d1 += 100
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

// d1 + 100
Date Date::operator+(int day) const
{
	Date tmp = *this;
	tmp += day;

	return tmp;
}

bool Date::operator<(const Date& d) const
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month < d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			return _day < d._day;
		}
	}
	return false;
}

bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator<=(const Date& d) const
{
	return *this < d || *this == d;
}

bool Date::operator>(const Date& d) const
{
	return !(*this <= d);
}

bool Date::operator>=(const Date& d) const
{
	return *this > d || *this == d;
}

bool Date::operator!=(const Date& d) const
{
	return !(*this == d);
}

////d1 - 100
//Date Date::operator-(int day)
//{
//	Date tmp = *this;
//	tmp._day -= day;
//
//	while (tmp._day <= 0)
//	{
//		--tmp._month;
//		if (tmp._month == 0)
//		{
//			tmp._month = 12;
//			--tmp._year;
//		}
//		tmp._day += GetMonthDay(tmp._year, tmp._month);
//	}
//
//	return tmp;
//}
//
////d1 -= 100
//Date& Date::operator-=(int day)
//{
//	*this = *this - day;
//
//	return *this;
//}

Date Date::operator-(int day) const
{
	Date tmp = *this;
	tmp -= day;

	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		if (_month == 0)
		{
			_month = 12;
			--_year;
		}
		_day += GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;

	return tmp;
}

Date& Date::operator++()
{
	Date tmp = *this;
	*this += 1;

	return tmp;
}

int Date::operator-(const Date& d) const
{
	int flag = 1;
	Date Max = *this;
	Date Min = d;

	if (Max < Min)
	{
		Max = d;
		Min = *this;
		flag = -1;
	}

	int num = 0;
	while (Min != Max)
	{
		++Min;
		++num;
	}

	return num * flag;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;

	return out;
}

istream& operator>>(istream& in, Date& d)
{
	while (1)
	{
		cout << "请依次输入年月日：";
		in >> d._year >> d._month >> d._day;

		if (!(d.CheckDate()))
		{
			cout << "输入日期非法:";
			d.Print();
			cout << "请重新输入!!!" << endl;
		}
		else
		{
			break;
		}
	}
	return in;
}