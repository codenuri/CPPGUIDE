#include <iostream>

class Test
{
public:
	// �����̸��� �Լ��� const, non-const �� ����� �ֽ��ϴ�.
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