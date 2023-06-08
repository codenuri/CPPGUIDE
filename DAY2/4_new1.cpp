#include <iostream>
#include <memory>

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
	// new �� �ϴ� ��
	// 1. �޸� �Ҵ�
	// 2. ������ ȣ��
//	Point* p1 = new Point(1, 2);

	// delete �� �ϴ���
	// 1. �Ҹ��� ȣ��
	// 2. �޸� ����
//	delete p1;

	// 1. ������ ȣ�� ���� �޸𸮸� �Ҵ�
	Point* p2 = static_cast<Point*>( operator new( sizeof(Point) )); // malloc �� ����

	
	// 2. �̹� �Ҵ�� �޸𸮿� �����ڸ� ȣ�� => placement new ��� �Ҹ��� ����Դϴ�.
	//new(p2) Point(1, 2);
	std::construct_at(p2, 1, 2); // C++20 ���� ����


	// 3. �޸� ���� ���� �Ҹ��ڸ� ȣ��
//	p2->~Point();
	std::destroy_at(p2); // C++17 ���� �����Ǵ� �Լ� <memory> ���


	// 4. �Ҹ��� ȣ�� ���� �޸𸮸� ����
	operator delete(p2); // free
}

// malloc : �޸� �Ҵ�
// new    : ��ü�� ����( �޸� �Ҵ� + ������ ȣ�� )


// new     Point(1,2) : ���ο� �޸𸮿� ��ü�� ������ �޶�� �ǹ�
// new(p2) Point(1,2) : �̹� �Ҵ�Ǿ� �ִ� �޸�(p2)�� ��ü�� ������ �޶�� ��
