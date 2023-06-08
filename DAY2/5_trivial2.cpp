#include <iostream>
#include <type_traits> 

class Test
{
//	int data;
	int data = 0; // 이 코드는 결국 생성자에서 초기화 하는 코드입니다
public:
//	virtual void foo() {} // 가상함수가 있으면 non-trivial

//	Test() {}	// 사용자가 생성자를 만들어도 non-trivial

	Test() = default; // = default 로 만들면 trivial
					  // 단, 다른 조건도 만족할때
};

int main()
{
	// trivial 여부를 조사하는 방법
	bool b = std::is_trivially_default_constructible_v<Test>;

	std::cout << b << std::endl;
}
// 생성자가 trivial 하다는 것의 의미
// => 객체를 생성할때 실제로 생성자가 호출되지 않습니다.
// => 기계어 코드 보면 생성자 호출이 생략되어 있습니다.