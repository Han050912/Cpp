#include"Date.h"

void TestDate1()
{
	Date d1(2024, 7, 12);
	Date d2 = d1 + 100;

	d1.Print();
	d2.Print();

	d1 += 30000;
	d1.Print();
}

void TestDate2()
{
	/*Date d1(2024, 7, 13);
	d1 -= 30000;
	d1.Print();*/

	Date d1(2024, 7, 13);
	Date ret1 = d1++;
	ret1.Print();
	d1.Print();

	Date d2(2024, 7, 13);
	Date ret2 = ++d2;
	ret2.Print();
	d2.Print();
}

void TestDate3()
{
	Date d1(2024, 7, 12);
	d1 += -100;
	d1.Print();

	d1 -= -100;
	d1.Print();
}

void TestDate4()
{
	Date d1(2034, 10, 1);
	Date d2(2024, 6, 31);

	cout << d1 - d2 << endl;
}

void TestDate5()
{
	Date d1, d2;
	cin >> d1 >> d2;
	cout << d1 << d2;

	cout << d1 - d2 << endl;

}

void TestDate6()
{
	const Date d1(2024, 7, 13);
	d1.Print();

	Date d2(2024, 7, 13);
	d2.Print();

	cout << &d1 << endl;
	cout << &d2 << endl;
}

//int main()
//{
//	TestDate6();
//
//	return 0;
//}

// 类型转换
class A
{
public:
	//给构造函数加explicit则禁止隐式转换
	//explicit A(int a = 0)
	A(int a = 0)
	{
		_a1 = a;
	}

	//初始化列表
	A(int a1, int a2)
		:_a1(a1)
		, _a2(a2)
	{
	}

	void Print() {
		cout << _a1 << " " << _a2 << endl;
	}
private:
	int _a1;
	int _a2;
};

class Stack
{
public:
	void Push(const A& aa)
	{
	}
private:
	A _arr[10];
	int _top;
};

int main()
{
	A aa1(1);
	aa1.Print();

	// 隐式类型转换
	// 用2构造了一个A的临时对象，再用这个临时对象拷贝构造aa2
	// 编译器遇到 构造临时对象+拷贝构造 会优化为直接构造
	A aa2 = 2;
	aa2.Print();

	A& raa1 = aa2;
	const A& raa2 = 2;

	Stack st;

	A aa3(3);
	st.Push(aa3);
	st.Push(3);

	// C++11
	A aa5 = { 1, 1 };
	const A& raa6 = { 2,2 };
	st.Push(aa5);
	st.Push({ 2,2 });

	return 0;
}