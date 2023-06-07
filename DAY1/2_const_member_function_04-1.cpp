#include <iostream>

class Test
{
public:
	// 동일이름의 함수는 const, non-const 로 만들수 있습니다.
	void foo()       { std::cout << "foo()\n"; }
	void foo() const { std::cout << "foo() const\n"; }
};
int main()
{
	Test t;
	t.foo();

	const Test ct;
	ct.foo();
}