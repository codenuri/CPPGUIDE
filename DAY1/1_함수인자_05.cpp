#include <iostream>
#include <string>

// 인자를 다른 함수에 전달하는 경우
// => 인자를 "forwarding" 한다 라고 표현합니다

// => 복사본도 만들면 안되고, const 도 추가 되면 안됩니다.
// => int&, int&&, const int&, 그리고 volatile 고려
//    그리고, int 뿐 아니라 모든 타입 고려..

// => 위 모든 경우를 자동생성하기 위해 template 사용(T&&) 사용
void f1(int  arg)  {}
void f2(int& arg) { arg = 100; }

template<typename F>
void forward_argument(F f, int& arg)
{
	f(arg);
}
template<typename F>
void forward_argument(F f, int&& arg)
{
	f(arg);
}
template<typename F>
void forward_argument(F f, const int& arg)
{
	f(arg);
}

int main()
{
	int n = 10;

	forward_argument(f1, 10);
	forward_argument(f2, n);
	const int c = 10;
	forward_argument(f1, c);
}


