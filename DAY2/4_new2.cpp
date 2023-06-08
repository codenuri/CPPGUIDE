#include <iostream>

class Point
{
	int x, y;
public:
	// �ٽ� : Point �� ����Ʈ �����ڰ� �����ϴ�.
	Point(int a, int b) { std::cout << "Point()" << std::endl; }
	~Point() { std::cout << "~Point()" << std::endl; }
	Point(const Point&) { std::cout << "Point(const Point&)" << std::endl; }
};
int main()
{
	// Point ��ü�� ���� �Ѱ��� ����� ������
	Point* p1 = new Point(1, 2);

	// Point ��ü�� ���� 10�� ����� ������
	// Point* p2 = new Point[10]; // error. ����Ʈ �����ڸ� 10�� ȣ���ؾ� �ϴ� �ڵ�
	
	// C++11 ���ʹ� �Ʒ� ó�� �ϴ� ����� �ֱ� �մϴ�.
	Point* p2 = new Point[10]{ {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0,},
							   {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0,} };


	// �ذ�å : �޸� �Ҵ�� ������ ȣ���� �и��ϸ� �˴ϴ�.
	Point* p3 = static_cast<Point*>(operator new(sizeof(Point) * 10));


	// ���� �Ҵ�� �޸� ������ 10���� ��ü�� �����մϴ�. (�����ڸ� ȣ���Ѵٴ��ǹ�)
	
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

