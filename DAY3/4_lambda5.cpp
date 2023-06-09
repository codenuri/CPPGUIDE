// T.141: Use an unnamed lambda 
//        if you need a simple function object in one place only

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// F.10: If an operation can be reused, give it a name
// F.11 : Use an unnamed lambda 
//        if you need a simple function object in one place only


int main()
{
	// 람다와 타입

	// 핵심 1. 완전히 동일한 람다 표현식 입니다. 
	// => 같은 타입일까요 ? 다른 타입일까요 ?
	// => 람다표현식은 모두 다른 타입입니다.
	auto f1 = [](int a, int b) {return a + b; };
				// class xxx{ operator()(int, int) }; xxx();

	auto f2 = [](int a, int b) {return a + b; };
				// class yyy{ operator()(int, int) }; yyy();


	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;



	// 핵심 2. 동일한 람다 표현식을 여러번 사용하는 경우. <== 중요
	std::vector<int> v = { 1,3,5,2,4,6 };

	// 아래 처럼 코드를 작성했다면 sort() 함수를 몇개 생성되었을까요 ?
	// => 모든 람다 표현식은 다른 타입이므로
	// => sort() 함수는 3개 생성됩니다.
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// 해결책 : 동일한 람다표현식이 여러번 사용되면 auto 변수에 담아서 사용하세요
	// => 아래 처럼 만들면 sort() 함수는 한개 만 생성됩니다.
	auto cmp = [](int a, int b) { return a < b; };
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);

	// 단, sort() 자체가 inline 이라면 위처럼 해도 됩니다.
	// 결국 sort() 함수가 생성되는것이 아니라, 사용하는 곳에 치환 되므로
	// 위, 아래 코드는 모두 동일하게 됩니다.
}
