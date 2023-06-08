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

	auto r3 = v.rbegin(); // std::make_reverse_iterator(v.end()); 客悼老
	auto r4 = v.rend();   // std::make_reverse_iterator(v.begin()); 客悼老

	while (r3 != r4)
	{
		std::cout << *r3 << std::endl;
		++r3;
	}
}
