// 	QA
#include <iostream>
#include <type_traits> // Ÿ�Կ� ���� �پ��� Ư���� �����ϴ� ���

// C++14 ���� ������ Ÿ���� ��� traits �� ���� ����Ҽ� �ְ� �ϱ� ����
// ������ ��������ϴ�.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;


template<typename T>
void foo(T a)
{
	// 1. ����
	bool b1 = std::is_pointer<T>::value; // C++11 ������ ���
	bool b2 = std::is_pointer_v<T>;      // C++17 ������ ���

	// 2. ������ Ÿ�� ���.
	typename std::remove_pointer<T>::type n2; // int n2;

	std::remove_pointer_t<T> n3;	// ���� �����ѵ�.. ����ϱ� �����ϴ�.
									// C++14 ���� ����!

//	std::is_
}

int main()
{
	int n = 0;
//	foo(n);
	foo(&n);
}