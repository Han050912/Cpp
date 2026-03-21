#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class Date
{
public:
	Date(int year = 2025,int month = 3,int day = 20)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void print()
	{

	}

//private:
	int _year;
	int _month;
	int _day;
};

bool operator==(Date x1,Date x2)
{
	return (x1._year == x2._year
		&& x1._month == x2._month
		&& x1._day == x2._day);
}

int main()
{
	Date d1;
	Date d2(2026, 3, 20);

	d1 == d2;

	return 0;
}

