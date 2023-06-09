#include <iostream>

// 람다의 원리

int main()
{
	

	//======================================================
	auto f1 = [](int a, int b) { return a + b; };

	// 위 한줄을 보고 컴파일러는 아래 코드로 변경 합니다
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
	// 람다 표현식은 지역변수를 캡쳐 할수 있습니다.
	// => 아래 코드는 "값에 의한 캡쳐" 입니다. 람다가 복사본을 보관하는 것
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
	// 아래 코드는 참조에 의한 캡쳐 입니다.	
	auto f3 = [&v1, &v2](int a, int b) { v1 = 100;  return a + b + v1 + v2; };

	f3(1, 2); // v1 == 100 이 실행. 실제 지역변수 변경

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