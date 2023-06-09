#include <iostream>

// C170. 람다표현식이 오버로딩이 필요 하면 generic 람다를 사용해라. - C++14

int main()
{
	auto add1 = [](int a, int b) { return a + b; };

	std::cout << add1(1,   2) << std::endl;		// 3
	std::cout << add1(1.1, 2.2) << std::endl;	// 3
	std::cout << add1(1,   2.2) << std::endl;	// 3
	std::cout << add1(1.1, 2) << std::endl;		// 3

	// C++14 generic 람다 : 인자가 auto 인 람다 표현식
	auto add2 = [](auto a, auto b) { return a + b; };

	std::cout << add2(1,   2) << std::endl;		// 3
	std::cout << add2(1.1, 2.2) << std::endl;	// 3.3
	std::cout << add2(1,   2.2) << std::endl;	// 3.2
	std::cout << add2(1.1, 2) << std::endl;		// 3.1
}

// generic람다원리 - add2 는 결국 아래 클래스 생성!
// => 핵심 2개의 인자가 다른 템플릿 이라는것!!!
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};
