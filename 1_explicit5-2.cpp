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

	// ����� ���� Ÿ���� cout ���� ����ϴ� ������ ������ ���ô�.

	std::cout << n << std::endl;
}