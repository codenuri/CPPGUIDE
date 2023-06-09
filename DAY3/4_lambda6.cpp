#include <vector>
#include <functional>
#include <vector>

int main()
{

	// 람다 표현식을 담는 방법
	// 1. auto 변수 에 담아서 사용
	//    => 한번 초기화 한후에는 다른 람다는 담을수 없습니다.
	auto f1 = [](int a, int b) { return a + b; };
					// class AAA{}; AAA();

//	f1 = [](int a, int b) { return a + b; }; // error
					// class BBB{}; BBB() 이므로 다른 타입



	// 2. std::function 에도 람다표현식을 담을수 있습니다.
	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };

	int ret = f3(1, 2);

	// f3 는 다른 람다 표현식(또는 함수, 함수객체)도 담을수(변경) 있습니다.
	f3 = [](int a, int b) { return a - b; };


	// 3. 여러개 람다를 컨테이너에 보관할때는 std::function 으로 하면 됩니다.

//	std::vector<auto> v1; // error
	
	std::vector<std::function<int(int, int)>> v2; // ok

	v2.push_back([](int a, int b) { return a - b; });
	v2.push_back([](int a, int b) { return a + b; });

}