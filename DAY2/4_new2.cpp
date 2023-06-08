#include <iostream>

class Point
{
	int x, y;
public:
	// 핵심 : Point 는 디폴트 생성자가 없습니다.
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	// Point 객체를 힙에 한개만 만들어 보세요
	Point* p1 = new Point(1, 2);

	// Point 객체를 힙에 10개 만들어 보세요
	// Point* p2 = new Point[10]; // error. 디폴트 생성자를 10번 호출해야 하는 코드
	
	// C++11 부터는 아래 처럼 하는 방법이 있긴 합니다.
	Point* p2 = new Point[10]{ {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0,},
							   {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0,} };


	// 해결책 : 메모리 할당과 생성자 호출을 분리하면 됩니다.
	Point* p3 = static_cast<Point*>(operator new(sizeof(Point) * 10));


	// 이제 할당된 메모리 공간에 10개의 객체를 생성합니다. (생성자를 호출한다는의미)
	
	for (int i = 0; i < 10; i++)
	{
		new(&p3[i]) Point(0, 0);  // std::construct_at(&p3[i], 0, 0);
	}

	for (int i = 0; i < 10; i++)
	{
		p3[i].~Point();
	}
	operator delete(p3);
}

