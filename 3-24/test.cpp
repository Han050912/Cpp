#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class A
{
public:
	A(int a1 = 0, int a2 = 0)
		:_a1(a1)
		, _a2(a2)
	{
		cout << "A(int a1 = 0, int a2 = 0)" << endl;
	}

	A(const A& aa)
		:_a1(aa._a1)
	{
		cout << "A(const A& aa)" << endl;

	}

	~A()
	{
		cout << "~A()" << endl;
	}

	A& operator=(const A& aa)
	{
		cout << "A& operator=(const A& aa)" << endl;
		if (this != &aa)
		{
			_a1 = aa._a1;
		}
		return *this;
	}

	A& operator++()
	{
		_a1 += 100;
		cout << "operator++()" << endl;

		return *this;
	}

	void Print() const
	{
		cout << "A::Print->" << _a1 << endl;
	}

private:
	int _a1 = 1;
	int _a2 = 1;
};

//int main()
//{
//	// 构造+拷贝构造 -> 直接构造
//	A aa1 = 1;
//	// 引用
//	const A& aa2 = 1;
//
//	return 0;
//}

//void f1(A aa)
//{
//}
//
//int main()
//{
//	A aa1(1);
//	f1(aa1);
//	cout << endl;
//
//	//匿名函数
//	f1(A(1));
//	cout << endl;
//
//	return 0;
//}

//A f2()
//{
//	A aa(1);
//	++aa;
//
//	return aa;
//}
//
//int main()
//{
//	f2().Print();
//	cout << "*********" << endl;
//
//	return 0;
//}

//A f2()
//{
//	A aa(1);
//	++aa;
//
//	return aa;
//}
//
//int main()
//{
//	A ret = f2();
//	ret.Print();
//	cout << "*********" << endl;
//
//	return 0;
//}

//A f2()
//{
//	A aa(1);
//	++aa;
//	cout << "##########" << endl;
//
//	return aa;
//}
//
//int main()
//{
//	A ret;
//	ret = f2();
//	ret.Print();
//	cout << "*********" << endl;
//
//	return 0;
//}

//int main()
//{
//	// 动态申请一个int类型的空间
//	int* p1 = new int;
//	// 动态申请10个int类型的空间
//	int* p2 = new int[10];
//
//	delete p1;
//	delete[] p2;
//
//	// 动态申请一个int类型的空间并初始化为0
//	int* p3 = new int(0);
//	int* p4 = new int[10] {0};
//	int* p5 = new int[10] {1, 2, 3, 4, 5};
//
//	delete p3;
//	delete[] p4;
//	delete[] p5;
//
//	return 0;
//}

////简单实现链表
//struct ListNode
//{
//	int val;
//	ListNode* next;
//
//	ListNode(int x)
//		:val(x)
//		, next(nullptr)
//	{
//	}
//};
//
//int main()
//{
//	// 动态申请一个A类型的空间
//	A* p1 = new A;
//	// 动态申请一个A类型的空间并初始化为1
//	A* p2 = new A(1);
//
//	delete p1;
//	delete p2;
//
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(1);
//	ListNode* n3 = new ListNode(1);
//	ListNode* n4 = new ListNode(1);
//	n1->next = n2;
//	n2->next = n3;
//	n3->next = n4;
//
//	return 0;
//}

//int main()
//{
//	A* p1 = new A(1);
//	A* p2 = new A(2, 2);
//
//	// 【方式1】使用已定义的对象初始化动态数组
//	A aa1(1, 1);
//	A aa2(2, 2);
//	A aa3(3, 3);
//	A* p3 = new A[3]{ aa1, aa2, aa3 };
//
//	// 【方式2】使用临时对象初始化动态数组
//	A* p4 = new A[3]{ A(1,1), A(2,2), A(3,3) };
//
//	// 【方式3】使用列表初始化
//	//A aa1 = { 1, 1 };
//	A* p5 = new A[3]{ {1,1}, {2,2}, {3,3} };
//
//	return 0;
//}

//// C++ 中使用 new 动态分配内存时，若分配失败会抛出异常（C语言返回空指针，不抛异常）
//int main()
//{
//	try
//	{
//		// throw try/catch 
//		void* p1 = new char[1024 * 1024 * 1024];
//		cout << p1 << endl;
//
//		void* p2 = new char[1024 * 1024 * 1024];
//		cout << p2 << endl;
//
//		void* p3 = new char[1024 * 1024 * 1024];
//		cout << p3 << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//
//	return 0;
//}

void func()
{
	int n = 1;
	while (1)
	{
		void* p1 = new char[1024 * 1024];
		cout << p1 << "->" << n << endl;
		++n;
	}
}

int main()
{
	try
	{
		func();
	}
	catch (const exception& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}



























class Solution {
public:
	string removeDuplicateLetters(string s) {
		vector<int> last(26, -1);   // 每个字母最后出现的位置
		vector<bool> in_stack(26, false); // 字母是否在栈中
		string stk;

		// 每个字符最后出现的位置
		for (int i = 0; i < s.size(); ++i) {
			last[s[i] - 'a'] = i;
		}

		for (int i = 0; i < s.size(); ++i) {
			char c = s[i];
			if (in_stack[c - 'a']) continue;

			while (!stk.empty() && c < stk.back() && last[stk.back() - 'a'] > i) {
				in_stack[stk.back() - 'a'] = false;
				stk.pop_back();
			}

			// 入栈
			stk.push_back(c);
			in_stack[c - 'a'] = true;
		}

		return stk;
	}
};