#pragma once

#include<iostream>
using namespace std;
#include<assert.h>

class Date
{
	//友元函数
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);
public:
	Date(int year = 1900, int month = 1, int day = 1);
	bool CheckDate() const;
	void Print() const;

	int GetMonthDay(int year, int month) const
	{
		assert(month > 0 && month < 13);

		static int monthDayArray[13] = { -1, 31, 28, 31, 30, 31, 30,
31, 31, 30, 31, 30, 31 };

		if ((month == 2) && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			return 29;
		}

		return monthDayArray[month];
	}

	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date operator+(int day) const;
	Date& operator+=(int day);

	Date operator-(int day)const;
	Date& operator-=(int day);

	//日期 - 日期
	int operator-(const Date& d) const;

	//日期++
	//C++规定，后置++重载时，增加⼀个int形参，跟前置++构成函数重载，方便区分。
	Date operator++(int);
	Date& operator++();

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& out, const Date& d);
istream& operator>>(istream& in, Date& d);