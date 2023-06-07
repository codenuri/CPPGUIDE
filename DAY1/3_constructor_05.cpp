#include <iostream>

class Point
{
	int x, y;
public:
	// 핵심 : Point 는 디폴트 생성자가 없다.
	Point(int a, int b) : x(a), y(b) { std::cout << "Point(int, int)" << std::endl; }
};

// Point p1;      // error
// Point p2(1,2); // ok

class Rect1
{
	Point ptFrom;
	Point ptTo;
public:
	/*
	// 사용자 코드	컴파일러가 변경한 코드
	Rect1()			// Rect1() : ptFrom(), ptTo() // <<== error
	{										// Point 에 디폴트 생성자없음.
		std::cout << "Rect()" << std::endl;
	}
	*/

	// 핵심 : 디폴트 생성자가 없는 타입을 멤버 데이타로 가진 경우.
	//       반드시 사용자가 멤버의 생성자를 명시적으로 호출해야 합니다.
	Rect1(): ptFrom(0, 0), ptTo(0, 0) {}
};

// 방법 2. C++11 부터는 아래 처럼해도 됩니다.
class Rect2
{
	Point ptFrom{ 0, 0 };
	Point ptTo{ 0, 0 };

//	Point ptTo(0, 0); // error. () 하지말고 {}로 하세요
public:
	// 위처럼 해도 결국은 아래 코드의 의미
//	Rect2() : ptFrom{ 0, 0 }, ptTo{ 0, 0 } {}
};

int main()
{
	Rect1 r;
}




