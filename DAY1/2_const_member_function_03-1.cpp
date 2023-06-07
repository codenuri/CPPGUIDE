#include <iostream>
#include <string>
#include <sstream>

class Point
{
	int x;
	int y;
	// mutable 멤버 데이타 : 상수 멤버 함수 안에서도 값을 변경할수 있게
	//						해달라는 지시어.
	mutable std::string cache;
	mutable bool cache_valid = false;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	std::string to_string() const
	{
		if (cache_valid == false)
		{
			std::stringstream oss;
			oss << x << ", " << y;
			cache = oss.str();
			cache_valid = true;
				// => x, y 값이 변경되면 cache_valid 를 false로
		}
		return cache;
	}
};

int main()
{
	const Point pt(1, 2);
	std::cout << pt.to_string() << std::endl;
	std::cout << pt.to_string() << std::endl;
}

