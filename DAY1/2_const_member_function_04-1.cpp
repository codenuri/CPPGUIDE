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
	Test t;  // ��� ��ü�� �ƴ�.
	t.foo(); // 1. "foo()" �� ���� ���õ�.. ���ٸ�
			 // 2. "foo() const" �� ���õ�. 

	const Test ct;
	ct.foo(); // "foo() const" �� ȣ�Ⱑ��. 
			  // ���ٸ� error
}