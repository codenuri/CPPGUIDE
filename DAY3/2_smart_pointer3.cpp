// R.11: Avoid calling new and delete explicitly
// R.1: Manage resources automatically using resource handles and RAII (Resource Acquisition Is Initialization)
// E.6: Use RAII to prevent leaks

#include <iostream>
#include <memory>

int main()
{
	// 자원을 아래처럼 할당했는데..
	int* p = new int;				

	// 자원의 해지는 스마트 포인터에 의존.
	std::shared_ptr<int> sp1(p);	
									
	std::shared_ptr<int> sp2 = sp1; // ok

	// 아래 처럼 raw pointer 를 다시 스마트 포인터에
	// 전달하면
	// => 관리객체가 2번 생성됩니다.
	std::shared_ptr<int> sp3(p); // bug...!!

	// 문제의 원인은 자원할당이 자원관리 객체가 초기화 될때 하지 않았습니다.
	// RAII 를 지키지 않은것
	int* p = new int;				// 자원할당
	std::shared_ptr<int> sp1(p);	// 자원관리 객체 초기화 - bad

	std::shared_ptr<int> sp1(new int);	//위보다는 좋지만, good은 아님.

	std::shared_ptr<int> sp1 = std::make_shared<int>(0); // good
}
