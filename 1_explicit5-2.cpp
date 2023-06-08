// 1_explicit5-2.cpp
#include <iostream>

class Integer
{
	int value;
public:
	Integer(int n) : value(n) {}

	//operator int() { return value; }
	operator int() { return 100; }
};

int main()
{
	Integer n(10);

	// 사용자 정의 타입을 cout 으로 출력하는 문제를 생각해 봅시다.
	// 방법 1. operator<<(ostream, Integer)  형식의 연산자 재정의함수 제공
	
	// 방법 2. std::cout  으로 출력 가능한 타입으로의 변환 연산자 제공.

	std::cout << n << std::endl;
}

// delete cin 과 cin << 5  코드에서 
// void pointer 변환연산자가 호출되는 게 헷갈리는데요,

delete cin; // cin 객체가 delete 가능한 타입으로 변환 가능한지 조사
		    // operator void*() 가 delete 가능하므로 호출한후 결과를 delete

cin << 5;   // cin 이 << 연산이 가능한지 타입으로 변환 가능한지 조사
			// operator bool() 이 있으면 ok
			// operator void*() 는 있어도 error.

// C++ : 컴파일러가 변환을 너무 많이 허용합니다 (버그 위험, 가독성 저하)
// 다른 언어 : 변환에 엄격합니다.

// C++ 에서 사용되는 용어
// "find_if 의 3번째 인자로 전달되는 함수의 반환타입이 bool 이어야 한다" 가아니라
// "find_if 의 3번째 인자로 전달되는 함수의 반환타입이 bool 로 변환 가능해야 한다."

// "operator void*() 가 delete 가능하다" 는 말씀의 인과관계가 잘 이해되지 않습니다.
// => C++ 문법에서 void* 를 delete 할수 있습니다.
void* p = new int;
delete p; // 단, 소멸자가 호출되지 않는 문제가 있어서 사용금지입니다.
          // 그래도, 컴파일은 됩니다.

