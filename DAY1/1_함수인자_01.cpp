#include <iostream>

struct Rect
{
	int left, top, right, bottom;

	Rect(int x1, int y1, int x2, int y2) 
		: left(x1), top(y1), right(x2), bottom(y2)
};
// 핵심 : call by value  vs  call by reference 이야기.

// 인자를 읽기만 할것이라면
// 1. call by value
// 단점 1. 복사본에 대한 오버 헤드
// 단점 2. 복사 생성자호출에 따른 오버헤드(자원을 사용하면 자원복사)
void bad1(Rect rc) {}

// 2. call by reference
// => 복사본 생성 안하고, 복사 생성자 호출 안됨
// 단점 1. 함수 내부에서 객체를 수정할수 있다. 
// 단점 2. 임시객체를 받을수 없다.
// => non-const reference 는 "write" 용도일때만 사용해야 합니다
void bad2(Rect& rc) {} 

void best(const Rect& rc) {}

int main()
{
	Rect rc = { 0, 0, 10, 10 };
	bad1(rc);
	bad2(rc); // ok
	bad2(Rect(0, 0, 10, 10)); // error. 임시객체를 non-const 참조로 받을수 없다

	best(rc);
	best(Rect(0, 0, 10,10));
}
