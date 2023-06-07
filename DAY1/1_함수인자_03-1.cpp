#include <iostream>
#include <string>
#include <string_view>

// string_view
// => 문자열에 대한 읽기 전용 view
int main()
{
	std::string s = "to be or not to be";

	std::string      ss = s; // 문자열을 자원을 복사
	std::string_view sv = s; // s 가 가진 문자열을 사용
							// 즉, s의 문자열을 대여(borrow) 해서 사용
							// 자신이 자원을 소유하지는 않은
							// sv 는 포인터 한개 + 문자열 길이만 관리
	//-------------------------------------------------------------
	// 아래 2줄의 차이도 명확히 알아 두세요
	std::string      ss1 = "to be or not to be";
							// => 힙을 할당하고 문자열 자체를 힙에 복사
	std::string_view sv1 = "to be or not to be";
							// => 상수 메모리에 있는 문자열을 가리키기만 한다

}