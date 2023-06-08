#include <iostream>

// C150. 가상함수에서는 절대 디폴트 인자를 변경하지 말라(사용하지 않으면 더 좋다.)

class Base
{
public:
	virtual void foo(int a = 10) { std::cout << "Base : " << a << std::endl; }
};
class Derived : public Base
{
public:
	virtual void foo(int a = 20) { std::cout << "Derived : " << a << std::endl; }
};

int main()
{
	Base* p = new Derived;
	p->foo();   // 실행하지 말고 결과 예측해 보세요
				// "Derived : 10"

	// 가상함수 : p 의 타입이 Base* 라도, 무조건 Base 것을 호출하지 않고
	//			 실행시간에 p가 가리키는 곳을 조사해서 함수를 결정
	// 
	// 디폴트 인자 : 컴파일러가 컴파일 시간에 채우게 된다.
	//		       컴파일시간에는 p의 타입만 알수 있다.

	p가리키는 곳을 실행시간에 조사후 결정된 객체의 타입의 ->foo(
						    컴파일러가 추가한 디폴트 값 10 );
}
// 이 격언의 핵심
// => 어떤 문법이 컴파일 시간에 동작하는지, 실행시간에 동작하는지 구별하세요
// 가상함수   : 실행시간에 함수를 결정
// 디폴트 인자 : 컴파일 시간에 채워준다.

// 되도록 실행시간 문법과 컴파일 시간 문법을 섞어서 사용하지 마세요
// => 가상함수에 디폴트 인자 사용등..