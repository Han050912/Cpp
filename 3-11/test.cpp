#include <iostream>
using namespace std;

//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//
//	void Print()
//	{
//		cout << this->_year << "/" << this->_month << "/" << _day << endl;
//	}
//
//private:
//	// 这里只是声明，没有开空间
//	int _year;
//	int _month;
//	int _day;
//};
//
////计算一下A/B/C实例化的对象是多大？（内存对齐）
//class A
//{
//public:
//	void Print()
//	{
//		cout << _ch << endl;
//	}
//private:
//	char _ch;
//	int _i;
//};
//
//class B
//{
//public:
//	void Print()
//	{
//
//	}
//};
//
//class C
//{ };
//
//int main()
//{
//	Date d1;
//	Date d2;
//
//	d1.Init(2026, 3, 11);
//	d1.Print();
//
//	d2.Init(2026, 3, 10);
//	d2.Print();
//
//	A a;
//	B b;
//	C c;
//
//	cout << sizeof(a) << endl;
//
//	cout << &b << endl;
//	cout << sizeof(b) << endl;
//
//	cout << &c << endl;
//	cout << sizeof(c) << endl;
//
//
//	return 0;
//}

////下面两个程序编译运行结果分别是什么？
//class A
//{
//public:
//	void Print()
//	{
//		cout << this << endl;
//		cout << "A::Print()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main()
//{
//	A* p = nullptr;
//				// mov  ecx  p
//	p->Print(); // call  地址
//
//	return 0;
//}

//class B
//{
//public:
//	void Print()
//	{
//		cout << this << endl;
//		cout << "B::Print()" << endl;
//		cout << _b << endl;
//	}
//private:
//	int _b;
//};
//
//int main()
//{
//	B* p = nullptr;
//	p->Print(); 
//
//	return 0;
//}

//class Date
//{
//public:
//	//无参构造函数
//	/*Date()
//	{
//		this->_year = 1;
//		this->_month = 1;
//		this->_day = 1;
//	}*/
//
//	//带参构造函数
//	/*Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//
//	//全缺省构造函数
//	Date(int year = 2026, int month = 3, int day = 10)
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
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	//Date d1;
//	//d1.Print();
//
//	Date d2(2026, 3, 11);
//	d2.Print();
//
//	//注意：如果通过无参构造函数创建对象时，对象后面不用跟括号（全缺省构造函数如果不给值的话也不带括号）
//	//否则编译器无法区分这里是函数声明还是实例化对象
//	Date d3;
//	d3.Print();
//	
//	return 0;
//}

//typedef int STDataType;
//
//class Stack
//{
//public:
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
//	//析构函数
//	~Stack()
//	{
//		free(_a);
//		_a = nullptr;
//		_capacity = _top = 0;
//	}
//
//private:
//	STDataType* _a;
//	size_t _capacity;
//	size_t _top;
//};
//
//class Queue
//{
//public:
//	// 编译器默认生成MyQueue的构造函数调用了Stack的构造，完成了两个成员的初始化
//	// 编译器默认生成MyQueue的析构函数调用了Stack的析构，释放Stack内部的资源
//	// 显式写析构，也会自动调用Stack的析构
//	~Queue()
//	{
//		cout << "~Queue " << endl;
//	}
//private:
//	Stack pushst;
//	Stack popst;
//	//此处编译器默认生成的构造对内置类型成员变量进行了初始化
//	int size;
//};
//
//int main()
//{
//	Queue q;
//	//Stack s1;
//	//Stack s2;
//
//	return 0;
//}

//// ⽤C++的构造和析构实现Stack
//bool isValid(const char* s) {
//	Stack st;
//	while (*s)
//	{
//		if (*s == '[' || *s == '(' || *s == '{')
//		{
//			st.Push(*s);
//		}
//		else
//		{
//			// 右括号⽐左括号多，数量匹配问题
//			if (st.Empty())
//			{
//				return false;
//			}
//			// 栈⾥⾯取左括号
//			char top = st.Top();
//			st.Pop();
//			// 顺序不匹配
//			if ((*s == ']' && top != '[')
//				|| (*s == '}' && top != '{')
//				|| (*s == ')' && top != '('))
//			{
//				return false;
//			}
//		}
//		++s;
//	}
//	// 栈为空，返回真，说明数量都匹配 左括号多，右括号少匹配问题
//	return st.Empty();
//}
//
//// ⽤C实现Stack
//bool isValid(const char* s) {
//	ST st;
//	STInit(&st);
//	while (*s)
//	{
//		// 左括号⼊栈
//		if (*s == '(' || *s == '[' || *s == '{')
//		{
//			STPush(&st, *s);
//		}
//		else // 右括号取栈顶左括号尝试匹配
//		{
//			if (STEmpty(&st))
//			{
//				STDestroy(&st);
//				return false;
//			}
//			char top = STTop(&st);
//			STPop(&st);
//			// 不匹配
//			if ((top == '(' && *s != ')')
//				|| (top == '{' && *s != '}')
//				|| (top == '[' && *s != ']'))
//			{
//				STDestroy(&st);
//				return false;
//			}
//		}
//		++s;
//	}
//	// 栈不为空，说明左括号⽐右括号多，数量不匹配
//	bool ret = STEmpty(&st);
//	STDestroy(&st);
//	return ret;
//}
//
//int main()
//{
//	cout << isValid("[()][]") << endl;
//	cout << isValid("[(])[]") << endl; 
//
//	return 0;
//}

class Date
{
public:
	//全缺省构造函数
	Date(int year = 2026, int month = 3, int day = 10)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

	bool operator==(Date d2)
	{
		return _year == d2._year
			&& _month == d2._month
			&& _day == d2._day;
	}

private:
	int _year;
	int _month;
	int _day;
};

//bool operator==(Date d1, Date d2)
//{
//	return d1._year == d2._year
//		&& d1._month == d2._month
//		&& d1._day == d2._day;
//}

int main()
{
	Date d1(2026,3,11);
	Date d2(2026,3,10);

	//operator==(d1, d2);
	d1 == d2;

	d1.operator==(d2);
	d1 == d2;

	return 0;
}