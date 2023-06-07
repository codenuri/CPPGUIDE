// 생성자와 가상함수
#include <iostream>

// 생성자에서는 가상함수가 동작하지 않습니다.
// 항상 자신의 함수를 호출하게 됩니다.

struct Base
{
	Base()     { init(); } // Base::init()

	void foo() { init(); }; // Derived::init()

	virtual void init() { std::cout << "Base::init" << std::endl; }     // 1
};
struct Derived : public Base
{
	int x;	
	
	// 사용자 코드			// 컴파일러 변경 코드
	Derived() : x(10) {}	// Derived() : Base(), x(10) {}

	virtual void init() { std::cout << "Derived::init : " << x << std::endl; } // 2
};
int main()
{
	Derived d;
//	d.foo();   // 결과 예측해 보세요
}
