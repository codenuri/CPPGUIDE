// �����ڿ� �����Լ�
#include <iostream>

// �����ڿ����� �����Լ��� �������� �ʽ��ϴ�.
// �׻� �ڽ��� �Լ��� ȣ���ϰ� �˴ϴ�.

struct Base
{
	Base()     { init(); } // Base::init()

	void foo() { init(); }; // Derived::init()

	virtual void init() { std::cout << "Base::init" << std::endl; }     // 1
};
struct Derived : public Base
{
	int x;	
	
	// ����� �ڵ�			// �����Ϸ� ���� �ڵ�
	Derived() : x(10) {}	// Derived() : Base(), x(10) {}

	virtual void init() { std::cout << "Derived::init : " << x << std::endl; } // 2
};
int main()
{
	Derived d;
//	d.foo();   // ��� ������ ������
}
