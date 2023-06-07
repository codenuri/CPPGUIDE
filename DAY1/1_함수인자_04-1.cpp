#include <iostream>
#include <string>

class Person
{
	std::string name;
	std::string address;
public:
	/*
	// 인자가 2개인 setter 에 대한 move 지원
	void set(const std::string& n, const std::string& a) 
	{ 
		name    = n; 
		address = a;
	}
	void set(std::string&& n, std::string&& a)
	{
		name    = std::move(n);
		address = std::move(a);
	}
	void set(std::string&& n, const std::string& a)
	{
		name = std::move(n);
		address = a;
	}
	void set(const std::string& n, std::string&& a)
	{
		name = n;
		address = std::move(a);
	}
	*/
	// 인자가 2개인 setter 를 move 지원하려면 => 4개의 함수 필요
	// 인자가 3개인 setter 를 move 지원하려면 => 9개의 함수 필요
	// 핵심 : 위 4개 함수를 자동생성되게 해야 합니다.
	//      => T&& 인자 사용(forwarding reference 라는 문법)

	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		addr = std::forward<T2>(a);
	}
};

int main()
{
	Person p;
	std::string s1 = "lee";
	std::string s2 = "seoul";

	p.set(s1, s2);
	p.set(s1, std::move(s2));

}