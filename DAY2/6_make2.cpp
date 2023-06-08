#include <iostream>
#include <tuple>
#include <vector>

int main()
{
	std::pair<int, double> p1(3, 3.4);
	std::tuple<int, double, int, double> t1(3, 3.4, 3, 3.4);

	// 위 2줄은 아래 2줄과 동일 합니다.
	auto p2 = std::make_pair(3, 3.4);
	auto t2 = std::make_tuple(3, 3.4, 3, 3.4);

	// 그런데, C++17 부터는 아래 처럼 해도 됩니다.
	std::pair p3(3, 3.4);
	std::tuple t3(3, 3.4, 3, 3.4);

	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector      v2 = { 1,2,3,4,5 }; // C++17 이후!!

}