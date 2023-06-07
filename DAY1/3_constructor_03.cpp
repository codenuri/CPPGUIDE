#include <iostream>

// 생성자 호출순서

struct BM	// Base class Member 라는 의미로 "BM" 이라고 했습니다
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
	
	// 사용자 코드		// 컴파일러가 변경한것
	Base()				// Base() : bm()
	{						
		std::cout << "Base()" << std::endl;
	}
	~Base()
	{
		std::cout << "~Base()" << std::endl;

		// ~bm() 소멸자는 ~Base() 코드가 먼저 실행되고 ~bm()호출
	}
};
struct Derived : public Base
{
	DM dm;

	// 사용자코드		// 컴파일러가 변경한 코드
	Derived()		// Derived() : Base(), dm() 
	{
		// call Base::Base()
		// call DM::DM() (멤버인 dm에 대해서)
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
