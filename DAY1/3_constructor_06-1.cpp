// �����ڿ� �����Լ�
#include <iostream>

// C.50: Use a factory function 
//       if you need ��virtual behavior" during initialization


struct Base
{
	Base() { } 

	virtual void init() { std::cout << "Base::init" << std::endl; }     // 1

	// factory function!
	template<typename T>
	static T* create()
	{
		T* p = new T; // ���� �����Ŀ�.. ������ ȣ���.

		p->init();    // �����Լ��� ȣ��!!
					  // �����ڰ� �ƴ�, ������ ȣ�� �������. 
						// �����Լ��� ȣ���ϹǷ�,, �����Լ��� �ߵ���
		return p;
	}
};


struct Derived : public Base
{
	int x;

	Derived() : x(10) {}

	virtual void init() { std::cout << "Derived::init : " << x << std::endl; } // 2
};
int main()
{
//	Derived d;

	Derived* p = Base::create<Derived>();
				// �����ϰ�, init() ȣ���ϴµ�..
			    // �ᱹ, ������������ init() �� ȣ���ϴ� �� ó��
				// �����Ҽ��ֽ��ϴ�.
}
