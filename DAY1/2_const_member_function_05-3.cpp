// 2_const_member_function_05-3.cpp
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3 };
	const std::vector<int> v2 = { 1,2,3 };

	// 동일이름을 가지는 const, non-const 함수를 동시에 제공하는
	// 경우는 아주 많습니다.
	auto p1 = v1.begin();
	auto p2 = v2.begin();

	*p1 = 10;
	*p2 = 10;
}