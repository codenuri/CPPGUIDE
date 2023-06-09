#include <iostream>
#include <string>

struct Resource
{
	Resource() { std::cout << "Resource()" << std::endl; }
	~Resource() { std::cout << "~Resource()" << std::endl; }
};
// 핵심 2. 자원을 직접 관리 하지 말고
//        자원 관리 객체에 의존해라   <== 요즘 C++ 의 핵심!!!
//			(new/delete 를 직접 사용하지 말라 라는 가이드)
// => 스마트 포인터를 사용하라는 의미

// => 생성자 호출에 실패(예외 발생) 하면 소멸자는 호출되지 않지만
// => 멤버의 생성자호출이 성공한 경우, 멤버의 소멸자는 호출됩니다.
// => 자원 관리는 스마트포인터로 하면, 항상 자원은 안전하게 해지 된다는 의미
class Test
{
//	Resource* res;
	std::unique_ptr<Resource> res;
public:
	Test() : res(new Resource)
	{
		throw std::runtime_error("exception in constructor");
	}
	~Test()
	{
		std::cout << "~Test()" << std::endl;

//		delete res;
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