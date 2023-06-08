#include <iostream>
#include <vector>
#include <iterator>
#include <ranges>   // C++20 의 핵심 STL 추가!!!

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8 };

	// 거꾸로 바로보는 view 에서 다시 3개만 볼수 있는 view 를 연결
	auto view = std::views::take( std::views::reverse(v), 3 );

	for (auto e : view )
	{
		std::cout << e << ", ";
	}
}
