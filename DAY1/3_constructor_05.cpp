#include <iostream>

class Point
{
	int x, y;
public:
	// �ٽ� : Point �� ����Ʈ �����ڰ� ����.
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
	// ����� �ڵ�	�����Ϸ��� ������ �ڵ�
	Rect1()			// Rect1() : ptFrom(), ptTo() // <<== error
	{										// Point �� ����Ʈ �����ھ���.
		std::cout << "Rect()" << std::endl;
	}
	*/

	// �ٽ� : ����Ʈ �����ڰ� ���� Ÿ���� ��� ����Ÿ�� ���� ���.
	//       �ݵ�� ����ڰ� ����� �����ڸ� ��������� ȣ���ؾ� �մϴ�.
	Rect1(): ptFrom(0, 0), ptTo(0, 0) {}
};

// ��� 2. C++11 ���ʹ� �Ʒ� ó���ص� �˴ϴ�.
class Rect2
{
	Point ptFrom{ 0, 0 };
	Point ptTo{ 0, 0 };

//	Point ptTo(0, 0); // error. () �������� {}�� �ϼ���
public:
	// ��ó�� �ص� �ᱹ�� �Ʒ� �ڵ��� �ǹ�
//	Rect2() : ptFrom{ 0, 0 }, ptTo{ 0, 0 } {}
};

int main()
{
	Rect1 r;
}




