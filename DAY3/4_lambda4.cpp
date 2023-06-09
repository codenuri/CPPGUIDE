#include <iostream>

// ������ ����

int main()
{
	

	//======================================================
	auto f1 = [](int a, int b) { return a + b; };

	// �� ������ ���� �����Ϸ��� �Ʒ� �ڵ�� ���� �մϴ�
	class CompilerGeneratedName1
	{
	public:
		int operator()(int a, int b) const 
		{
			return a + b;
		};
	};
	auto f1_1 = CompilerGeneratedName1();

	//======================================================
	// ���� ǥ������ ���������� ĸ�� �Ҽ� �ֽ��ϴ�.
	// => �Ʒ� �ڵ�� "���� ���� ĸ��" �Դϴ�. ���ٰ� ���纻�� �����ϴ� ��
	int v1 = 10, v2 = 10;

	auto f2 = [v1, v2](int a, int b) { return a + b + v1 + v2; };
	
	std::cout << sizeof(f2) << std::endl; // ?

	class CompilerGeneratedName2
	{
		int v1;
		int v2;
	public:
		CompilerGeneratedName2(int a, int b) : v1(a), v2(b) {}

		int operator()(int a, int b) const
		{
			return a + b + v1 + v2;
		};
	};
	auto f2_1 = CompilerGeneratedName2(v1, v2);


	//=======================================================
	// �Ʒ� �ڵ�� ������ ���� ĸ�� �Դϴ�.	
	auto f3 = [&v1, &v2](int a, int b) { v1 = 100;  return a + b + v1 + v2; };

	f3(1, 2); // v1 == 100 �� ����. ���� �������� ����

	std::cout << v1 << std::endl; // 100


	class CompilerGeneratedName3
	{
		int& v1;
		int& v2;
	public:
		CompilerGeneratedName3(int& a, int& b) : v1(a), v2(b) {}

		int operator()(int a, int b) const
		{
			v1 = 100;
			return a + b + v1 + v2;
		};
	};
	auto f3_1 = CompilerGeneratedName3(v1, v2);
	 
}