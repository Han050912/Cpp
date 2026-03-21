#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include"Date.h"


//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void Func1(Date d)
//{
//	cout << &d << endl;
//	d.Print();
//}
//
//int main()
//{
//	Date d1(2024, 7, 12);
//	d1.Print();
//
//	// 传值传参要调用拷贝构造
//	Func1(d1);
//
//	Date d2(d1);
//	d2.Print();
//	Date d3 = d2;
//	d3.Print();
//
//	return 0;
//}

//typedef int STDataType;
//class Stack
//{
//public:
//	//构造函数
//	Stack(int n = 4)
//	{
//		_a = (STDataType*)malloc(sizeof(STDataType) * n);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败");
//			return;
//		}
//		_capacity = n;
//		_top = 0;
//	}
//
//	// 拷贝构造函数
//	Stack(const Stack& st)
//	{
//		// 需要对_a指向资源创建同样大的资源再拷贝值
//		_a = (STDataType*)malloc(sizeof(STDataType) * st._capacity);
//		if (nullptr == _a)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//		memcpy(_a, st._a, sizeof(STDataType) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//
//	void Push(STDataType x)
//	{
//		if (_top == _capacity)
//		{
//			int newcapacity = _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_a, newcapacity *
//				sizeof(STDataType));
//			if (tmp == NULL)
//			{
//				perror("realloc fail");
//				return;
//			}
//			_a = tmp;
//			_capacity = newcapacity;
//		}
//		_a[_top++] = x;
//	}
//
//	//析构函数
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//		free(_a);
//		_a = nullptr;
//		_top = _capacity = 0;
//	}
//
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};

//int main()
//{
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//
//	// Stack不显式实现拷贝构造，用自动生成的拷贝构造完成浅拷贝
//	// 会导致st1和st2里面的_a指针指向同一块资源，析构时会析构两次，程序崩溃
//	Stack st2(st1);
//
//	return 0;
//}

//void func1(const Stack& st)
//{
//
//}
//
//// 两个Stack实现队列
//class MyQueue
//{
//public:
//private:
//	Stack pushst;
//	Stack popst;
//};

//int main()
//{
//	Stack st1;
//	func1(st1);
//
//	MyQueue mq1;
//	MyQueue mq2(mq1);
//
//	return 0;
//}

////传引用返回，减少拷贝构造函数的调用
//Stack& func2(Stack& st)
//{
//	st.Push(1);
//	st.Push(1);
//	st.Push(1);
//
//	return st;
//}
//
//int main()
//{
//	Stack st1;
//	func2(st1);
//
//	return 0;
//}

//class A
//{
//public:
//	void func()
//	{
//		cout << "A::func()" << endl;
//	}
//};
//
//typedef void(A::* PF)();
//
//int main()
//{
//	PF pf = nullptr;
//
//	// C++规定成员函数要加&才能取到函数指针
//	//error C3867: “A::func”: 非标准语法；请使用 "&" 来创建指向成员的指针
//	//pf = A::func;
//	pf = &A::func;
//	A aa;
//	(aa.*pf)();
//
//	return 0;
//}

////运算符重载
//class Date
//{
//public:
//	//构造函数
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//
//		return *this;
//	}
//
//	// 拷贝构造
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//
//	// 构造，第一个参数是指针类型，不是自身类类型的引用
//	Date(const Date* d)
//	{
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}
//
//	bool operator==(const Date& d)
//	{
//		return _year == d._year
//			&& _month == d._month
//			&& _day == d._day;
//	}
//
//	//d1 + 100;
//	Date operator+(int day);
//
//	//d1 - 100;
//	Date operator-(int day);
//
//	// d1 - d2;
//	int operator-(const Date& d);
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

// 写在全局无法访问类中的私有变量
//bool operator==(const Date& d1, const Date& d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}

//int main()
//{
//	Date d1(2024, 7, 5);
//	Date d2(2024, 7, 6);
//
//	// 运算符重载函数可以显式调用
//	//operator==(d1, d2);
//	// 编译器会转换成 operator==(d1, d2);
//	//d1 == d2;
//
//	d1.operator==(d2);
//	d1 == d2;
//
//	d1 + 100;
//	d1 - 100;
//	d1 - d2;
//
//	return 0;
//}

//int main()
//{
//	Date d1(2024, 7, 5);
//	Date d2(2024, 7, 6);
//
//	//赋值运算符重载
//	d1 = d2;
//
//	// 拷贝构造
//	Date d3(d2);
//	Date d4 = d2;
//
//	d4 = d3 = d1;
//
//	int i, j, k;
//	i = j = k = 1;
//
//	return 0;
//}

int main()
{
	Date d1(2026, 3, 22);
	Date d2 = d1 + 100;
	// Date d3(d1 + 100);
	d1.Print();
	d2.Print();

	d1 += 30000;
	d1.Print();

	return 0;
}