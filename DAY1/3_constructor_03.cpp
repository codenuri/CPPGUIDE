#include <iostream>

// ������ ȣ�����

struct BM	// Base class Member ��� �ǹ̷� "BM" �̶�� �߽��ϴ�
{
	BM()  { std::cout << "BM()" << std::endl; }
	~BM() { std::cout << "~BM()" << std::endl; }
};

struct DM	// Derived class Member
{
	DM() { std::cout << "DM()" << std::endl; }
	~DM() { std::cout << "~DM()" << std::endl; }
};

struct Base
{
	BM bm;
	
	// ����� �ڵ�		// �����Ϸ��� �����Ѱ�
	Base()				// Base() : bm()
	{						
		std::cout << "Base()" << std::endl;
	}
	~Base()
	{
		std::cout << "~Base()" << std::endl;

		// ~bm() �Ҹ��ڴ� ~Base() �ڵ尡 ���� ����ǰ� ~bm()ȣ��
	}
};
struct Derived : public Base
{
	DM dm;

	// ������ڵ�		// �����Ϸ��� ������ �ڵ�
	Derived()		// Derived() : Base(), dm() 
	{
		// call Base::Base()
		// call DM::DM() (����� dm�� ���ؼ�)
		std::cout << "Derived()" << std::endl;
	}
	~Derived()
	{
		std::cout << "~Derived()" << std::endl;
		// ~dm()
		// ~Base()
	}
};
int main()
{
	Derived d; // call Derived::Derived()

}
