#include <string>

// 핵심 : 멤버 데이타를 초기화 할때는 
//       항상 초기화 리스트가 좋습니다.

class People1
{
	std::string name;
	int age;
public:
	People1(const std::string& s, int a) 
		: name(s), age(a)		// good
	{							// name 에 대해서
								// string(const string&s) 버전 생성자
								// 1회 호출로 초기화.!
	}
};

class People2
{
	std::string name;
	int age;
public:
	// 사용자 코드							// 컴파일러 추가 코드
	People2(const std::string& s, int a)	// : name() 
	{										
		name = s;	// bad.
					// 1. name 의 디폴트 생성자가 호출된후
					// 2. 대입연산자 (name.operator=(s)) 로 값 대입
					// 즉, 2번의 함수 호출 발생
		age = a;
	}
};

int main()
{
	std::string s = "john";
	People1 p1(s, 20);
	People2 p2(s, 20);
}

// 참고 string 은 alias 입니다. 실제 클래스는 "basic_string 입니다.
/*
using string = std::basic_string<char,
							std::char_traits<char>,
							std::allocator<char>>;
							*/