#include <iostream>

class Point
{
	int x, y;
public:
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};

int main()
{
	// new 가 하는 일
	// 1. 메모리 할당
	// 2. 생성자 호출
//	Point* p1 = new Point(1, 2);

	// delete 가 하는일
	// 1. 소멸자 호출
	// 2. 메모리 해지
//	delete p1;

	// 1. 생성자 호출 없이 메모리만 할당
	Point* p2 = static_cast<Point*>( operator new( sizeof(Point) )); // malloc 과 유사

	
	// 2. 이미 할당된 메모리에 생성자만 호출
	new(p2) Point(1, 2);


	// 3. 메모리 해지 없이 소멸자만 호출
	p2->~Point();


	// 4. 소멸자 호출 없이 메모리만 제거
	operator delete(p2); // free

}