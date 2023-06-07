#include <iostream>

class Point
{
public:
	int x, y;

	Point(int a, int b) : x(a), y(b) {}

	// ��� �Լ� ȣ���� ����
	// pt.set(10, 20) ==> set(&pt, 10, 20) ���� ����˴ϴ�. 
	// ��ü�� ��� �Լ��� ����ó�� ���޵Ǵ� ��
	void set(int a, int b) // set( Point* this, int a, int b)
	{                      // {
		x = a;			   //		this->x = a;
		y = b;			   //		this->y = b;
	}					   // }

//	void print()			// void print(Point* this)
	void print() const      // void print(const Point* this)
	{
//		x = 10; // error. 
				// this->x = 10 �ε�
				// this �� ��� ��ü�� ����Ű�� ������ �̹Ƿ�..
		std::cout << x << ", " << y << std::endl;
	}
};
int main()
{
//	Point pt(1, 2);
	// �ٽ� 1. pt �� ��� ��ü �Դϴ�.
	const Point pt(1, 2);

	pt.x = 10;		// error. public �� ������ ����̹Ƿ�
	pt.set(10, 20); // error. 
					// set(&pt, 10, 20);

	pt.print();     // error. print(&pt);
					// ��, print �� ��� ��� �Լ���� ok.
}
// �ٽ� : ��� ��ü�� ��� ����Լ� �� ȣ�Ⱑ���մϴ�.
//		