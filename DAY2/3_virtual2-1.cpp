#include <iostream>

// C++ Core Guideline 저자
// C++ 창시자
// herb shutter => MS 수석아키텍쳐 - VS 팀에서 
//				Coreguide line 검사 툴을 만들려고 시도 했음.

// C35. 기반 클래스 소멸자는 public - virtual 이거나
//      protected - non virtual 이어야 한다.

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
	// 기반 클래스의 소멸자를 가상함수로 해야 하는 이유는 아래 코드 
	// 때문입니다. 
	// 아래 처럼 사용하는 코드가 없으면 가상함수가 아니어도 됩니다.
	Base* p = new Derived;	
//	delete p;	// error. protected 에 있는 소멸자를 외부에서 호출 안됨

	delete static_cast<Derived*>(p); // ok
}