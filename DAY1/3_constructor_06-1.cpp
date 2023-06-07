// 생성자와 가상함수
#include <iostream>

// C.50: Use a factory function 
//       if you need “virtual behavior" during initialization


struct Base
{
	Base() { } 

	virtual void init() { std::cout << "Base::init" << std::endl; }     // 1

	// factory function!
	template<typename T>
	static T* create()
	{
		T* p = new T; // 먼저 만든후에.. 생성자 호출됨.

		p->init();    // 가상함수를 호출!!
					  // 생성자가 아닌, 생성자 호출 종료된후. 
						// 가상함수를 호출하므로,, 가상함수가 잘동작
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
				// 생성하고, init() 호출하는데..
			    // 결국, 생성과정에서 init() 을 호출하는 것 처럼
				// 생각할수있습니다.
}
