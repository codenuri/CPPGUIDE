#include <iostream>
#include <vector>
#include <iterator>

template<typename T>
class reverse_view
{
	T& rgn;
public:
	reverse_view(T& r) : rgn(r) {}
	auto begin() { return rgn.rbegin(); }
	auto end()   { return rgn.rend(); }
};
int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8 };
	
	reverse_view rv(v); // 컨테이너 v 를 거꾸로 바라볼수 있는 뷰(view)
	
	//for (auto e : v)
	//for (auto e : rv)
	for (auto e : reverse_view(v) )
	{
		std::cout << e << ", ";
	}
}
// 	for (auto e : v) 원리 : v.begin(), v.end() 를 호출해서 반복자를 
//						   꺼내는것