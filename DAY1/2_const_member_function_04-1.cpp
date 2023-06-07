#include <iostream>

class Test
{
public:
	// 동일이름의 함수를 const, non-const 로 만들수 있습니다.
	void foo()       { std::cout << "foo()\n"; }
	void foo() const { std::cout << "foo() const\n"; }
};
int main()
{
	Test t;  // 상수 객체가 아님.
	t.foo(); // 1. "foo()" 가 먼저 선택됨.. 없다면
			 // 2. "foo() const" 가 선택됨. 

	const Test ct;
	ct.foo(); // "foo() const" 만 호출가능. 
			  // 없다면 error
}