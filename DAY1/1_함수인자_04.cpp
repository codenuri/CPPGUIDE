#include <iostream>
#include <string>

class Person
{
	std::string name;
public:
	// 1. C++11 이전까지는 아래 코드는 best 입니다.
	//    하지만 C++11 이후는 부족합니다.
//	void set_name(const std::string& n) { name = n; } // 자원을 항상 복사
//	void set_name(const std::string& n) { name = std::move(n); } 
									// => 자원을 항상 복사
									// => const 객체는 move 될수 없습니다.

	// 결론, move를 지원하려면 setter 를 2개 만들어야 합니다
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	// 왜 이경우에는 "string_view" 를 사용하지 않나요 ?
	// => 이 경우는 결국 "name" 멤버가 문자열을 소유하게 됩니다.
	// => 즉, 어차피 문자열 자체는 힙에 올라가야 합니다.
	// => 그래서 string_view 가 아닌 const std::string& 로 해도 상관없습니다.
};

int main()
{
	Person p;

	std::string s = "lee";
	p.set_name(s);				// s의 문자열을 복사해 가라는 것
	p.set_name(std::move(s));	// s의 자원을 복사하지 말고 가져가라는것
	p.set_name("kim");
}