#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda(또는 함수객체) when a function won't do 
//      (to capture local variables, or to write a local function)



// 일반 함수 에서는 main 에 있는 지역변수 k를 사용할수 없습니다.
// => 캡쳐 능력 없음.
bool foo(int n) { return n % 3 == 0; }


class IsModulus
{
	int value;
public:
	IsModulus(int n) : value(n) {}

	bool operator()(int n) const
	{
		return n % value == 0;
	}
};

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k = 3;

	IsModulus f(k); // f는 내부적으로 k의 값을 보관합니다.(값을 캡쳐했습니다.)
	bool b = f(10); // 10 % k 의 의미. 즉, 캡쳐된 값으로 연산 수행.

	auto ret1 = std::find_if(v.begin(), v.end(), f);
									//함수와 지역변수 k를 같이 전달하는 의미

	// 한번 사용한다면.. 아래 처럼 임시객체로 만들어서 사용하면 됩니다.
	// 클래스이름() : 임시로 사용하는 객체 생성

	auto ret2 = std::find_if(v.begin(), v.end(), IsModulus(k) );

}
