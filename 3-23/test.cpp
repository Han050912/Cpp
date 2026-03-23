#include <iostream>
#include <algorithm>
using namespace std;

//class Time
//{
//public:
//	Time(int hour)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int& xx, int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day)
//		,_n(1)
//		,_ref(xx)
//		,_t(1)
//		, _ptr((int*)malloc(12))
//	{
//		if (_ptr == nullptr)
//		{
//			perror("malloc fail");
//		}
//		else
//		{
//			memset(_ptr, 0, 12);
//		}
//	}
//
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	// 声明
//	int _year;
//	int _month;
//	int _day;
//
//	const int _n;
//	int& _ref;
//	Time _t;
//
//	int* _ptr;
//};
//
//int main()
//{
//	int x = 0;
//	Date d1(x, 2026, 3, 23);
//	d1.Print();
//
//	return 0;
//}

//class Time
//{
//public:
//	Time(int hour)
//		:_hour(hour)
//	{
//		cout << "Time()" << endl;
//	}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		//,_day(day)
//	{
//	}
//
//	void Print() const
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//
//private:
//	//缺省值，是给没有显示在初始化列表初始化的成员使用的。（C++11）
//	int _year = 2;
//	int _month = 2;
//	int _day;
//
//	int* _ptr = (int*)malloc(12);
//	Time _t = 2;
//};
//
//int main()
//{
//	Date d1(2026,3);
//	d1.Print();
//
//	Date d2;
//	d2.Print();
//
//	return 0;
//}

////下面程序的运行结果是什么?
//class A
//{
//public:
//	A(int a)
//		:_a1(a)
//		, _a2(_a1)
//	{
//	}
//
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//
//private:
//	int _a2 = 2;
//	int _a1 = 2;
//};
//
//int main()
//{
//	A aa(1);
//	aa.Print();
//}

////static关键字
//class A
//{
//public:
//	A()
//	{
//		++_count;
//		cout << "构造函数+1" << endl;
//	}
//
//	A(const A& a)
//	{
//		++_count;
//		cout << "拷贝构造函数+1" << endl;
//	}
//
//	~A()
//	{
//		--_count;
//		cout << "析构函数-1" << endl;
//	}
//
//	static int GetCount()
//	{
//		//_a++;   //静态成员函数不能访问非静态成员变量
//		return _count;
//	}
//
//private:
//	static int _count;
//
//	int _a = 1;
//};
//
//int A::_count = 0;
//
//int main()
//{
//	//cout << A::_count << endl;
//	cout << sizeof(A) << endl;
//
//	cout << A::GetCount() << endl; 
//
//	A a1, a2;  
//
//	{
//		A a3(a1);  
//		cout << A::GetCount() << endl; 
//	}  // a3 离开作用域，析构
//
//	cout << A::GetCount() << endl;  
//	cout << a1.GetCount() << endl;  
//
//	return 0;
//}

//class Solution {
//private:
//    static int _n;
//    static int _ret;
//
//    class Sum {
//    public:
//        Sum() {
//            _ret += _n;
//            _n++;
//        }
//
//    };
//
//public:
//    int Sum_Solution(int n) {
//        Sum* s = new Sum[n];
//        delete[] s; 
//        return _ret;
//    }
//
//};
//
//int Solution::_n = 1;
//int Solution::_ret = 0;


////前置声明，否则A的友元函数声明编译器不认识B
//class B;
//
//class A
//{
//	// 友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//class B
//{
//	// 友元声明
//	friend void func(const A& aa, const B& bb);
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//
//void func(const A& aa, const B& bb)
//{
//	cout << aa._a1 << endl;
//	cout << bb._b1 << endl;
//}
//
//int main()
//{
//	A aa;
//	B bb;
//	func(aa, bb);
//
//	return 0;
//}

////友元类
//class A
//{
//	friend class B;
//private:
//	int _a1 = 1;
//	int _a2 = 2;
//};
//
//class B
//{
//public:
//	void Func1(const A& aa)
//	{
//		cout << aa._a1 << endl;
//	    cout << _b1 << endl;
//	}
//
//	void Func2(const A& aa)
//	{
//		cout << aa._a2 << endl;
//		cout << _b2 << endl;
//	}
//
//private:
//	int _b1 = 3;
//	int _b2 = 4;
//};
//
//int main()
//{
//	A a;
//	B b;
//	b.Func1(a);
//	b.Func2(a);
//
//	return 0;
//}

////内部类
//class A
//{
//private:
//	static int _k;
//	int _h = 1;
//public:
//	class B // B默认就是A的友元
//	{
//	public:
//		void Func(const A& a)
//		{
//			cout << _k << endl; 
//			cout << a._h << endl;
//		}
//	private:
//		int _b = 1;
//	};
//};
//
//int A::_k = 1;
//
//int main()
//{
//	cout << sizeof(A) << endl;
//
//	A::B b;
//	A aa;
//	b.Func(aa);
//
//	return 0;
//}

//匿名对象
class A
{
public:
	A(int a = 0)
		:_a(a)
	{
		cout << "A(int a)" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

private:
	int _a;
};

bool myfunction(int i, int j) { return (i > j); }

int main()
{
	A aa1;  

	// 匿名对象的生命周期只在当前一行
	A(); // 匿名对象
	A(1);


	int a[] = { 32,71,12,45,26,80,53,33 };
	// < 升序
	sort(a, a + 8);

	// > 降序
	// sort(a, a + 8, myfunction);

	/*greater<int> gt;
	sort(a, a + 8, gt);*/

	sort(a, a + 8, greater<int>());

	return 0;
}