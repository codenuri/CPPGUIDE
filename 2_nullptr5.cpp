// 2_nullptr5.cpp
#include <iostream>

int main()
{
	// nullptr : true, false 같은 키워드 이고..
	//			 리터럴(값) 입니다
	//			 rvalue 입니다.
	// 
	// true, false : bool 타입
	// nullptr     : std::nullptr_t 타입

	// 1. nullptr 타입 알아 두세요
	std::nullptr_t mynull = nullptr;

	// 2. 이제 mynull 을 nullptr 대신 사용가능합니다.
	int* p1  = mynull;
	char* p2 = mynull;
}