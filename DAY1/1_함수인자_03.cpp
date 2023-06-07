#include <iostream>
#include <string>
#include <string_view> // C++17 부터 지원 됩니다.
	
// ~ C++14 : const std::string& 이 최선
// C++17 ~ : std::string_view 가 최선

// 그렇다면 string 외에도 vector 같이 연속된 메모리를 사용하는
// 것들에 대한 view 도 필요 하지 않을까요 ?
// => C++20 에서 std::span 이 연속된 메모리에 대한 view 입니다.
//    string_view 의 일반화 버전... std::span<int> int_view;

// 또하나의 중요한 개념 "대여(borrow)" 의 개념입니다.
// string      : 자원을 소유
// string_view : 자원을 대여


// std::string 을 읽기만 하는 경우

void bad(std::string s)
{
}
void good(const std::string& s) {}

// 아래 코드가 최선의 선택 입니다.
// std::string_view : call by value 로 받는 것이 원칙
void best(std::string_view s) {}

int main()
{
	std::string s = "to be or not to be";

	bad(s);
	// 아래 2줄의 경우 유사 합니다.
	good(s); // 포인터 한개, 접근시 2번 참조
	best(s); // 포인터 한개 + 길이, 접근시 1번 참조

	// 핵심 : 아래 2줄을 생각해 보세요
	good("to be or not to be");
	best("to be or not to be");
}