
// 3_strength2 - 1.cpp
#include <iostream>

constexpr std::pair<int, bool> max(int a, int b)
{
//	std::cout << "max\n"; // 이 코드가 있으면 컴파일 시간에
						  // 수행 될수 없습니다.
//	bool b = std::is_constant_evaluated(); // C++20 

	return std::pair<int, bool>(a + b, std::is_constant_evaluated());
}

int main()
{
	// 아래 결과는 C++ 컴파일러마다 다릅니다. 
	//									cl컴파일러
//	auto ret = max(1, 2);			// false
	
	const auto ret = max(1, 2);		// false 

//	constexpr auto ret = max(1, 2);	// true

	std::cout << ret.second << std::endl;
}