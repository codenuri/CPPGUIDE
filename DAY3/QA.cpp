// 	QA
#include <iostream>
#include <type_traits> // 타입에 대한 다양한 특성을 조사하는 기술

// C++14 에서 변형된 타입을 얻는 traits 를 쉽게 사용할수 있게 하기 위해
// 별명을 만들었습니다.
template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;


template<typename T>
void foo(T a)
{
	// 1. 조사
	bool b1 = std::is_pointer<T>::value; // C++11 시절의 기술
	bool b2 = std::is_pointer_v<T>;      // C++17 시절의 기술

	// 2. 변형된 타입 얻기.
	typename std::remove_pointer<T>::type n2; // int n2;

	std::remove_pointer_t<T> n3;	// 위와 동일한데.. 사용하기 쉽습니다.
									// C++14 부터 지원!

//	std::is_
}

int main()
{
	int n = 0;
//	foo(n);
	foo(&n);
}