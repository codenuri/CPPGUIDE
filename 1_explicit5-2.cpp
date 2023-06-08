// 1_explicit5-2.cpp
#include <iostream>

class Integer
{
	int value;
public:
	Integer(int n) : value(n) {}
};

int main()
{
	Integer n(10);

	// 사용자 정의 타입을 cout 으로 출력하는 문제를 생각해 봅시다.

	std::cout << n << std::endl;
}