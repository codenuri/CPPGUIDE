#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8 };

	auto last = v.end(); // 마지막 다음

	// reverse 반복자 : 인자로 받은 반복자의 한개 앞을 가리키고
	//					++연산시 --로 동작
	std::reverse_iterator< ? > rfirst(last);

	++rfirst; // 일반 반복자의 -- 의미

	std::cout << *rfirst << std::endl;
}