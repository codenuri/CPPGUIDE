// move.cpp
#include <iostream>
#include <string>

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	// C++11 부터 move 개념이 등장합니다.
	std::string s3 = s1;	// 복사생성자 호출
							// 자원의 깊은 복사
							// 문자열 자체를 복사

	std::string s4 = std::move(s2);
							// 이동 생성자 호출
							// s2의 문자열을 s4가 빼았아서 사용

}