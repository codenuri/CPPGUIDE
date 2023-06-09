
// F50 ~ F54 - 람다 표현식 사용한 관한 코딩 관례
// F.50 : Use a lambda when a function won't do 
//        (to capture local variables, or to write a local function)
// F.52 : Prefer capturing by reference in lambdas that will be used locally, including passed to algorithms
// F.53 : Avoid capturing by reference in lambdas that will be used non - locally, including returned, stored on the heap, or passed to another thread
// F.54 : If you capture this, capture all variables explicitly(no default capture)



#include <iostream>
// 함수 객체 ( function object )
// => () 연산자를 재정의 해서 함수 처럼 사용가능한 객체
struct plus
{
	int operator()(int a, int b) const 
	{
		return a + b;
	}
};
int main()
{
	plus p;	// p는 객체 입니다.(plus 타입)
			// p는 함수가 아닙니다.

	int n1 = p(1, 2);	// 객체인 p를 함수 처럼 사용합니다.
						// "함수 객체" 라고 합니다

	int n2 = p.operator()(1, 2); // ok.. 위 코드와 완전히 동일
}