#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "Func.h"

//// 永远不要返回局部变量（或临时对象）的引用或指针
//int& func()
//{
//	int a = 0;
//	return a;
//}

////引用的特性
//int main()
//{
//	int a = 10;
//
//	// 编译报错：“ra”: 必须初始化引用
//	//int& ra;
//
//	int& b = a;
//	int c = 20;
//
//	//引用一旦引用一个实体，再不能引用其他实体
//	b = c;
//
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << &c << endl;
//
//	return 0;
//}

////引用的使用
//void Swap(int& rx, int& ry)
//{
//	int tmp = rx;
//	rx = ry;
//	ry = tmp;
//}
//
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* a;
//	int top;
//	int capacity;
//}ST;
//
//void STInit(ST& rs, int n = 4)
//{
//	rs.a = (STDataType*)malloc(n * sizeof(STDataType));
//	rs.top = 0;
//	rs.capacity = n;
//}
//
//// 栈顶
//void STPush(ST& rs, STDataType x)
//{
//	// 满了， 扩容
//	if (rs.top == rs.capacity)
//	{
//		printf("扩容\n");
//		int newcapacity = rs.capacity == 0 ? 4 : rs.capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(rs.a, newcapacity *
//			sizeof(STDataType));
//		if (tmp == NULL)
//		{
//			perror("realloc fail");
//			return;
//		}
//		rs.a = tmp;
//		rs.capacity = newcapacity;
//	}
//	rs.a[rs.top] = x;
//	rs.top++;
//}
//
//// int STTop(ST& rs)
////引用做返回值，减少拷贝提高效率和改变引用对象时同时改变被引用对象。
//int& STTop(ST& rs)
//{
//	return rs.a[rs.top];
//}
//
//int main()
//{
//	// 调用全局的
//	ST st1;
//	STInit(st1);
//	STPush(st1, 1);
//	STPush(st1, 2);
//	cout << STTop(st1) << endl;
//
//	//由于STTop返回的是引用，因此可以直接通过赋值或复合赋值修改栈顶元素
//	STTop(st1) += 10;
//	cout << STTop(st1) << endl;
//	return 0;
//}

//// 函数模版，T可以任意类型
//template<class T>
//void func(const T& val)
//{
//
//}
//
//void func(const int& val)
//{
//
//}
//
//int main()
//{
//	const int a = 0;
//	//可以引用一个const对象，但是必须用const引用
//	//int& b = a;
//	const int& b = a;
//
//	//const也可以引用普通对象，因为对象的访问权限在引用过程中可以缩小，但是不能放大
//	int c = 0;
//	const int& d = c;
//	c++;
//	//d++;
//	cout << &c << endl;
//	cout << &d << endl;
//
//	const int& i = 10;
//	const int& j = a + c;
//
//	double x = 3.14;
//	int y = x;
//	const int& z = x;
//	cout << "x = " << x << endl;  
//	cout << "y = " << y << endl;   
//	cout << "z = " << z << endl;   
//
//	x = 5.67;        
//
//	cout << "x改变为5.67后:" << endl;
//	cout << "x = " << x << endl;  
//	cout << "y = " << y << endl;   
//	cout << "z = " << z << endl;   
//
//	func(a);
//	func(b);
//	func(30);
//	func(a + b);
//	func(d);
//
//	return 0;
//}

//////////////////////////////////////////////////////////////////////

//inline

// 实现一个ADD宏函数的常见问题
//#define ADD(int a, int b) return a + b;
//#define ADD(a, b) a + b;
//#define ADD(a, b) (a + b)

////正确的宏实现
//#define ADD(a, b) ((a) + (b))
//
//int main()
//{
//	// 为什么不能加分号?
//	int ret = ADD(1, 2);  // ->int ret = ((1)+(2));
//	cout << ADD(1, 2) << endl;
//
//	// 为什么要加外面的括号?
//	cout << ADD(1, 2) * 5 << endl;  // -> (1) + (2) * 5
//
//	// 为什么要加里面的括号?
//	int x = 1, y = 2;
//	ADD(x & y, x | y); // ->(x & y + x | y)
//
//	return 0;
//}

//inline int Add(int x, int y)
//{
//	int ret = x + y;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//	ret += 1;
//
//	return ret;
//}
//
//int main()
//{
//	int ret = Add(1, 2);
//	cout << Add(1, 2) * 5 << endl;
//	cout << ret << endl;
//
//	//链接错误：无法解析的外部符号 "void __cdecl f(int)" (?f@@YAXH@Z)，函数 main 中引用了该符号
//	//inline不建议声明和定义分离到两个文件，分离会导致链接错误。
//	//因为inline被展开，就没有函数地址，链接时会出现报错。
//	f(1);
//
//	return 0;
//}

//void f(int x)
//{
//	cout << "f(int x)" << endl;
//}
//
//void f(int* ptr)
//{
//	cout << "f(int* ptr)" << endl;
//}
//
//int main()
//{
//	f(0);
//	f(NULL);
//	// 编译报错：error C2665: “f”: 2 个重载中没有一个可以转换所有参数类型
//	//f((void*)0);
//
//	f(nullptr);
//
//	//C++禁止 void* 隐式转换为其他指针类型，必须使用强制转换
//	void* p1 = NULL;
//	int* p2 = (int*)p1;
//
//	int* p2 = nullptr;
//	//“初始化”: 无法从“nullptr”转换为“int”
//	//int i = nullptr;
//
//	return 0;
//}

//class Stack
//{
//	//public:
//	void Push(int x)
//	{
//	}
//public:
//	void Pop()
//	{
//	}
//
//	int Top()
//	{
//		return 0;
//	}
//private:
//	int* a;
//	int top;
//	int capacity;
//};
//
//class Queue
//{
//public:
//	//不同的类域可以定义同名的成员（包括成员变量、成员函数、类型别名等），因为它们属于不同的作用域，不会冲突。
//	void Push(int x)
//	{
//	}
//};
//
//int main()
//{
//	Stack st;
//	st.Pop();
//	st.Top();
//	//被private修饰的成员在类外无法被直接访问
//	//st.Push(1);
//	//st.a;
//
//
//
//	return 0;
//}


// class Date
struct Date
{
public:
	void Init(int year, int month, int day);

private:
	// 为了区分成员变量，一般习惯上成员变量会加一个特殊标识
	int _year;
	int _month;
	int _day;
};

// 声明和定义分离，需要指定类域
void Date::Init(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

// 兼容C的struct用法
typedef struct ListNodeC
{
	int val;
	struct ListNodeC* next;
}LTNodeC;

// CPP
struct ListNodeCPP
{
	int val;
	ListNodeCPP* next;
};

int main()
{
	Date d1;
	Date d2;

	d1.Init(2024, 7, 9);

	struct Date d3;

	ListNodeCPP node;

	// Date::_year = 2024;

	return 0;
}