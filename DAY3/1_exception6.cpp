#include <iostream>
#include <vector>

// noexcept 를 붙이는 이유
// 1. 컴파일러가 좀더 효율적인 기계어 코드를 생성합니다.
// 
// 2. 라이브러리 내부에서 noexcept 가 붙은 경우와 붙지 않은 경우에
//    다르게 처리하는 경우가 있습니다.

// move 계열 함수는 noexcept 로 만들어야 한다.

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy ctor" << std::endl; }
	Object(Object&&)  noexcept    { std::cout << "move ctor" << std::endl; }
};

int main()
{
	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	// vector 는 내부적으로 Object 의 move 생성자를 조사해서
	// 예외가 없다면 : move 생성자 사용
	// 예외가능성이 있다면 : copy 생성자 사용

	// Object 의 move 생성자의 예외 여부는 : 사용자가 알려줘야 합니다.
	//								move 생성자 뒤에 noexcept 표기
	v.resize(10); // 이순간의 원리를 생각해봅시다.

	std::cout << "----------------" << std::endl;
}

// GUIDE : 함수가 예외가 없음을 보장할수 있다면 noexcept 붙이세요
// 그런데, 쉽지 않습니다.
// 1. move 생성자, move 대입연산자는 반드시 noexcept 붙이세요
// 2. 자원 해지 함수들은 꼭 noexcept 붙이세요
// 3. 소멸자는 디폴트가 noexcept

// 그외에는 확신이 없으면 붙이지 마세요.

// 예외가 생각보다 어렵고 복잡합니다.
// => 그래서 rust 는 예외가 없습니다..