#include <iostream>
#include <string>

struct Resource
{
	Resource() { std::cout << "Resource()" << std::endl; }
	~Resource() { std::cout << "~Resource()" << std::endl; }
};

// 해결책 1. two phase initialization(constructor)
// => 2단 초기화(생성자 호출)이라는 기술.

// 핵심 : 생성자에서는 실패 가능성이 없는 초기화만 한다
//       (예외가 발생하지 않는 초기화 )
// => 생성자 실패하지 않기 때문에, 항상 소멸자가 호출된다는 것을 보장한다.

class Test
{
	int value;
	Resource* res;
public:
	Test() : value(0), res(nullptr)  {}

	// 실패 가능성이 있는 초기화는 별도의 멤버 함수로 제공한다.
	void construct()
	{
		res = new Resource;

		throw std::runtime_error("exception in construct");
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
		Test t;			// 한번
		t.construct();	// 두번에 거쳐서 객체가 초기화 됩니다.
						// 그래서 2단 초기화(생성자호출) 라는 이름 사용
	}
	catch (...) {}
}
// 삼성의 타이젠(예전의 바다 OS)이나 일부 오픈소스에서 볼수 있습니다.