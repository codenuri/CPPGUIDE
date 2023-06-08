#include <iostream>

// C35. ��� Ŭ���� �Ҹ��ڴ� virtual �̰ų� protected �̾�� �Ѵ�.

// �ٽ� : ����� ����ϴ� ��� "��� Ŭ���� �Ҹ��ڴ� �ݵ�� �����Լ�" �� �ϼ���.

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	virtual ~Base() { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public: 
	Derived()  { std::cout << "Derived()" << std::endl; }
	~Derived() { std::cout << "~Derived()" << std::endl; } 
};
int main()
{
//	Derived d;
//	Derived* p = new Derived;	// Derived()
//	delete p;					// ~Derived()

	// �ٽ�!! �Ʒ� �ڵ��� ����� Ȯ���� ������.
	Base* p = new Derived;	// Derived() ȣ��
	
	delete p;	// 1. �Ҹ��� ȣ��
				// 2. �޸� ����.

	// �� 2���� �߿� 1. �Ҹ��� ȣ����
	// �Ҹ��ڰ� �����Լ��� �ƴϸ� : ������ Ÿ�Ը� ���� ���� => ~Base() ��ȣ��
	// �Ҹ��ڰ� �����Լ����     : p�� ����Ű�� ���� �����ؼ� �Ҹ���ȣ���� ����
}