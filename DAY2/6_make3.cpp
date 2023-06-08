#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8 };

	auto last = v.end(); // 마지막 다음


	// reverse 반복자 : 인자로 받은 반복자의 한개 앞을 가리키고
	//					++연산시 --로 동작
	// last 타입 : std::vector<int>::iterator 
//	std::reverse_iterator< std::vector<int>::iterator > rfirst( last ); // C++17이전
//	std::reverse_iterator rfirst(last); // C++17 이후

	// C++17 이전은 도움함수를 사용하면 템플릿 인자 생략가능
	auto rfirst = std::make_reverse_iterator(last);

	++rfirst; // 일반 반복자의 -- 의미

	std::cout << *rfirst << std::endl; // 7
}
// 결론
// => 이미 C++ STL 안에는 make_ 를 사용해서 클래스 템플릿의 객체를 생성하는 많은
//    함수가 있습니다.
// => 그런데, C++17 이후 부터는 많이 사용되지 않을수 있습니다.!!