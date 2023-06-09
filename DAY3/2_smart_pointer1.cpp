// R.22 : Use make_shared() to make shared_ptrs
// R.23 : Use make_unique() to make unique_ptrs

#include <iostream>
#include <memory>

struct Point
{
	int x;
	int y;
	
	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// 핵심 1. C++ 표준 스마트 포인터는 생성자가 explicit 입니다.
//	std::shared_ptr<Point> sp1 = new Point(1, 2); // error
	std::shared_ptr<Point> sp2(new Point(1, 2));  // ok. bad
												// 직접 new 하지 말라.

	// 핵심 2. 스마트 포인터를 사용하려면 std::make_shared()로 만들어서 사용해라.
	std::shared_ptr<Point> sp3 = std::make_shared<Point>(1, 2); // good
}






