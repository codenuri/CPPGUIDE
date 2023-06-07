#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	// 멤버 함수 호출의 원리
	// pt.set(10, 20) ==> set(&pt, 10, 20) 으로 변경됩니다. 
	// 객체가 멤버 함수의 인자처럼 전달되는 것
	void set(int a, int b) // set( Point* this, int a, int b)
	{                      // {
		x = a;			   //		this->x = a;
		y = b;			   //		this->y = b;
	}					   // }

//	void print()			// void print(Point* this)
	void print() const      // void print(const Point* this)
	{
//		x = 10; // error. 
				// this->x = 10 인데
				// this 가 상수 객체를 가리키는 포인터 이므로..
		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
//	Point pt(1, 2);
	// 핵심 1. pt 는 상수 객체 입니다.
	const Point pt(1, 2);

	pt.x = 10;		// error. public 에 있지만 상수이므로
	pt.set(10, 20); // error. 
					// set(&pt, 10, 20);

	pt.print();     // error. print(&pt);
					// 단, print 가 상수 멤버 함수라면 ok.
}
// 핵심 : 상수 객체는 상수 멤버함수 만 호출가능합니다.
//		