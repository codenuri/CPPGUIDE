#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8 };
	
	auto p1 = v.begin();
	auto p2 = v.end();

	auto r1 = std::make_reverse_iterator(v.end());
	auto r2 = std::make_reverse_iterator(v.begin());

	auto r3 = v.rbegin(); // std::make_reverse_iterator(v.end()); 와동일
	auto r4 = v.rend();   // std::make_reverse_iterator(v.begin()); 와동일

	while (r3 != r4)
	{
		std::cout << *r3 << std::endl;
		++r3;
	}

	auto ret1 = std::find(v.begin(), v.end(), 3); // 정방향으로 검색
	auto ret2 = std::find(v.rbegin(), v.rend(), 3); // 뒤에서 부터 검색.

	// reverse iterator 덕분에 STL 의  모든 알고리즘은
	// 순방향, 역방향 모두 가능합니다.
}
