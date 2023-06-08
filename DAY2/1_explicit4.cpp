#include <iostream>

int main()
{
	int n = 0;

	std::cin >> n; // 만약 "a" 를 입력 한다면 ?
					// 입력 실패, n값 변화 없음.

	std::cout << n << std::endl; // 0.. 
		// 1. 10      2. 0     3. -1     4. 97

	// 입력 성공/실패 여부를 조사하는 방법
	// 1. fail() 멤버 함수 사용..
	if (std::cin.fail()) {}

	// 2. 객체의 scalar test 기술..(객체를 if 에 넣기)
	if (std::cin)   // C++98 : cin.operator void*()
	{				// C++11 : cin.operator bool()
		// 성공..
	}


}