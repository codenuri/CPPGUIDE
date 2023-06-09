// 2_const_member_function_06.cpp
#include <iostream>

class Point
{
	int x, y;
public:
	void f1(int a, int b)  // void f1(Point* this, int a, int b)
	{	
		x = a; 	y = b;
		std::cout << "f1\n"; 
	}
	// C++23 에서 등장하는 새로운 멤버 함수 모양
	// => explicit object parameter 라는 문법
	// => "deducing this" 라는 별명을 가진 기술.
	void f2(this Point& self, int a, int b)
	{
		self.x = a; 	self.y = b;
		std::cout << "f2\n";
	}
};
int main()
{
	Point pt;
	pt.f1(10, 20); // f1(&pt, 10, 20)
	pt.f2(10, 20);
}