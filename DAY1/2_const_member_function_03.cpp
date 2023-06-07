#include <iostream>
#include <string>
#include <sstream>

class Point
{
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// 객체의 상태를 문자열로 반환하는 함수(디버깅등에 유용)
	// => C#, java, rust 등의 대부분의 언어에서 볼수 있는 멤버함수
	// => 상수 객체도 상태를 출력해 볼수 있어야 하므로 const 멤버함수로
	std::string to_string() const 
	{
		std::stringstream oss; // oss 안에 string 이 있습니다.
		oss << x << ", " << y; // string 에 쓰기
		return oss.str();      
	}
};

int main()
{
	const Point pt(1, 2);
	std::cout << pt.to_string() << std::endl;
	std::cout << pt.to_string() << std::endl;
}

