#include <iostream>
#include <string>

struct Resource
{
	Resource()  { std::cout << "Resource()" << std::endl; }
	~Resource() { std::cout << "~Resource()" << std::endl; }
};
// 핵심 1. 생성자 호출에 실패(생성자에서 예외 발생)
//	      소멸자가 호출되지 않습니다.
// => 자원 누수의 가능성이 있습니다. ( 아래 코드 참고 )
class Test
{
	Resource* res;
public:
	Test() : res(new Resource)
	{
		throw std::runtime_error("exception in constructor");
	}
	~Test()
	{
		delete res;
	}
};
int main()
{
	try
	{
		Test t;
	}
	catch (...) {}
}