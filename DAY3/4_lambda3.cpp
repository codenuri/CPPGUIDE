#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// local function

int main()
{
	// 1. C++은 함수 안에서 함수 만들수 없습니다.
	// => nested function 또는 local function 이라는 개념
	// => C#, swift, rust 는 가능합니다.
//	int add(int a, int b) { return a + b; }; // error

	// 2. 하지만 함수 안에서 클래스, 구조체를 만들수 있습니다.
	class AAA {}; // ok

	// 3. 그래서, 함수 안에서 함수는 만들수 없어도, 함수객체는 만들수 있습니다.
	struct plus
	{
		int operator()(int a, int b) const { return a + b; }
	};
	plus p;
	int n = p(1, 2);
}