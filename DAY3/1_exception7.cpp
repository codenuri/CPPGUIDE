#include <iostream>

// C.36 : A destructor must not fail
// C.37 : Make destructors noexcept
//			=> 소멸자는 noexcept 를 표기하지 않아도 noexcept 입니다.

class Object
{
public:
	~Object() 
	{
		std::cout << "~Object()\n";

		// 아래 코드느 절대 사용하면 안됩니다.
		// 소멸자는 예외를 던질수 없습니다.
		//throw std::runtime_error("my exception");
	}
};

void foo()
{
	Object obj;
	throw std::runtime_error("my exception");
			// => 예외가 발생되어서 지역변수의 소멸자는 안전하게 호출됩니다.
			// => 스택 풀기( stack unwinding ) 이라는 기술
			// => 대부분의 객체지향 언어가 가지는 특징

	std::cout << "finish foo" << std::endl;
}

int main()
{
	try
	{
		foo();
	}
	catch (...)
	{
	}
}