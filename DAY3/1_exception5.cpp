// F.6  : If your function must not throw, 
//        declare it noexcept

// noexcept 키워드
// 1. 함수가 예외가 있는지 조사할때 사용
// 2. 함수를 만들때 예외가 없다고 컴파일러 한테 알려주는 것
#include <iostream>

void f1() { }
void f2() noexcept { }

int main()
{
	// noexcept( 함수호출식 ) : "함수호출식" 대로 사용시 예외가능성
	//						  이 있는지 조사
	//				함수 선언 뒤에 noexcept가 붙어 있는지 조사.
	bool b1 = noexcept( f1() );
	bool b2 = noexcept( f2() );

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}