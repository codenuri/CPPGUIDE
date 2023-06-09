#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda(또는 함수객체) when a function won't do 
//      (to capture local variables, or to write a local function)



bool foo(int n) { return n % 3 == 0; }

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	// 1. 주어진 구간에서 첫번째 나오는 "3"을 찾아라
	auto ret1 = std::find(v.begin(), v.end(), 3);


	// 2. 주어진 구간에서 첫번째 나오는 "3의 배수"를 찾아라
	auto ret2 = std::find_if(v.begin(), v.end(), foo);

	// 값   찾기 : find  (first, last, 값);
	// 조건 찾기 : find_if(first, last, 함수);



	// 3. 주어진 구간에서 첫번째 나오는 "k의 배수"를 찾아라
	int k = 3;
	std::cin >> k;
	auto ret2 = std::find_if(v.begin(), v.end(), "foo 함수 + 지역변수 k");

	// 필요한것 : k값을 보관해서 사용할수 있는 함수가 필요!!
	// 일반함수 : main 의 지역변수를 캡쳐하는 능력이 없다.
	// 함수객체 : main 의 지역변수를 캡쳐하는 능력이 있다.
}
