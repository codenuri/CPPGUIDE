#include <iostream>

// C35. 기반 클래스 소멸자는 virtual 이거나 protected 이어야 한다.

// 핵심 : 상속을 사용하는 경우 "기반 클래스 소멸자는 반드시 가상함수" 로 하세요.

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

	// 핵심!! 아래 코드의 결과를 확인해 보세요.
	Base* p = new Derived;	// Derived() 호출
	
	delete p;	// 1. 소멸자 호출
				// 2. 메모리 해지.

	// 위 2가지 중에 1. 소멸자 호출은
	// 소멸자가 가상함수가 아니면 : 포인터 타입를 보고 결정 => ~Base() 만호출
	// 소멸자가 가상함수라면     : p가 가리키는 곳을 조사해서 소멸자호출을 결정
}