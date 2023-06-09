#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// local function

int main()
{
	// 1. C++�� �Լ� �ȿ��� �Լ� ����� �����ϴ�.
	// => nested function �Ǵ� local function �̶�� ����
	// => C#, swift, rust �� �����մϴ�.
//	int add(int a, int b) { return a + b; }; // error

	// 2. ������ �Լ� �ȿ��� Ŭ����, ����ü�� ����� �ֽ��ϴ�.
	class AAA {}; // ok

	// 3. �׷���, �Լ� �ȿ��� �Լ��� ����� ���, �Լ���ü�� ����� �ֽ��ϴ�.
	struct plus
	{
		int operator()(int a, int b) const { return a + b; }
	};
	plus p;
	int n = p(1, 2);
}