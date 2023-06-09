#include <iostream>

// C170. ����ǥ������ �����ε��� �ʿ� �ϸ� generic ���ٸ� ����ض�. - C++14

int main()
{
	auto add1 = [](int a, int b) { return a + b; };

	std::cout << add1(1,   2) << std::endl;		// 3
	std::cout << add1(1.1, 2.2) << std::endl;	// 3
	std::cout << add1(1,   2.2) << std::endl;	// 3
	std::cout << add1(1.1, 2) << std::endl;		// 3

	// C++14 generic ���� : ���ڰ� auto �� ���� ǥ����
	auto add2 = [](auto a, auto b) { return a + b; };

	std::cout << add2(1,   2) << std::endl;		// 3
	std::cout << add2(1.1, 2.2) << std::endl;	// 3.3
	std::cout << add2(1,   2.2) << std::endl;	// 3.2
	std::cout << add2(1.1, 2) << std::endl;		// 3.1
}

// generic���ٿ��� - add2 �� �ᱹ �Ʒ� Ŭ���� ����!
// => �ٽ� 2���� ���ڰ� �ٸ� ���ø� �̶�°�!!!
class CompilerGeneratedName
{
public:
	template<typename T1, typename T2>
	auto operator()(T1 a, T2 b) const
	{
		return a + b;
	}
};
