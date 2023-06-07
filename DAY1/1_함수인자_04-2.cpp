#include <iostream>
#include <string_view>
#include <string>
#include <array>

class Person
{
	std::string name;
	std::string address;
	std::array<int, 32> data;
public:
	// move 를 고려하는 경우 : 인자로 받은 것을 멤버에 보관할때(즉, setter)
	
	// 그외는 고려 할필요 없습니다.

	// 1. 인자로 받은 것을 멤버에 보관하지 않고
	//    함수 내부적으로 사용만 할때
	// => move 고려 대상 아닙니다.
	//void print_msg(const std::string& msg) // good
	void print_msg(std::string_view msg)     // best
	{
		std::cout << msg << std::endl;
	}

	// 2. move 는 동적 할당을 사용하는 타입에서만 성능향상이 있습니다
	//    특정 타입은 move 이 장점이 없는 경우가 있습니다.
	// => 아래 코드는 인자를 멤버 에 보관하지만
	// => std::array 자체는 move 사용시 성능향상의 효과는 없습니다.
	void set_data(const std::array<int, 32>& d)
	{
		data = d;
	}
};

int main()
{
	Person p;

	std::string s = "to be or no to be";
	std::array<int, 32> arr = { 0 };

	p.print_msg(s);
	p.set_data(arr);
}