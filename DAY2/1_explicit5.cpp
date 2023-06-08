// 변환의 위험성.. 그리고 explicit 

// C++ 표준 라이브러리인 std::cin 을 생각해 봅시다.
class istream
{
	struct dummy
	{
		// 주소만 사용하기 위해 만든 함수
		void true_function() {}
	};
public:
	bool fail() { return true; }

//	operator bool()  { return fail() ? false : true; }
//	operator void*() { return fail() ? 0     : this; }

	using F = void (dummy::*)();
	operator F () { return fail() ? 0 : &dummy::true_function; }
};
istream cin;

int main()
{
	// 아래 처럼 if 문으로 cin 입력의 유효성을 조사하고 싶었다.
	if (cin) { }

	// 방법 1. bool 로의 변환. 
	cin << 5; // 잘못 사용했다( >> 로 해야 하는데 << 로 사용)
			  // 그런데, 에러가 아니다.
	// 방법 2. void* 로 변환
	// => if() 에 놓일수 있고, cin << 5 는 에러!
	// => 그런데..
	delete cin; // 이 코드가 에러가 아니다.
			    // C++98 시절에 delete std::cin 이 에러가 아님.

	// 방법 3. boost 라이브러리 팀이.. 보다 안전한 방법을 제시합니다.
	// => 멤버 함수의 포인터로의 변환
	// => "safe bool" 이라고 불리는 기술.

	// => 객체를 if 문에 넣을수 있게 하는데..
	// => side effect 를 최소화 해서 버그를 막는 기술
	// => "멤버 함수 포인터"로 변환이 최선이다!! - C++98 시절의 격언
}