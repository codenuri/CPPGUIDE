#include <iostream>

// C++ Core Guideline ����
// C++ â����
// herb shutter => MS ������Ű���� - VS ������ 
//				Coreguide line �˻� ���� ������� �õ� ����.

// C35. ��� Ŭ���� �Ҹ��ڴ� public - virtual �̰ų�
//      protected - non virtual �̾�� �Ѵ�.

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }

protected:
	~Base() { std::cout << "~Base()" << std::endl; }
};

class Derived : public Base
{
public:
	Derived() { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; }
};
int main()
{
	// ��� Ŭ������ �Ҹ��ڸ� �����Լ��� �ؾ� �ϴ� ������ �Ʒ� �ڵ� 
	// �����Դϴ�. 
	// �Ʒ� ó�� ����ϴ� �ڵ尡 ������ �����Լ��� �ƴϾ �˴ϴ�.
	Base* p = new Derived;	
//	delete p;	// error. protected �� �ִ� �Ҹ��ڸ� �ܺο��� ȣ�� �ȵ�

	delete static_cast<Derived*>(p); // ok
}