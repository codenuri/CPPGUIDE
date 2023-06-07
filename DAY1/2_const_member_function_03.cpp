#include <iostream>
#include <string>
#include <sstream>

class Point
{
	int x;
	int y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) {}

	// ��ü�� ���¸� ���ڿ��� ��ȯ�ϴ� �Լ�(����� ����)
	// => C#, java, rust ���� ��κ��� ���� ���� �ִ� ����Լ�
	// => ��� ��ü�� ���¸� ����� ���� �־�� �ϹǷ� const ����Լ���
	std::string to_string() const 
	{
		std::stringstream oss; // oss �ȿ� string �� �ֽ��ϴ�.
		oss << x << ", " << y; // string �� ����
		return oss.str();      
	}
};

int main()
{
	const Point pt(1, 2);
	std::cout << pt.to_string() << std::endl;
	std::cout << pt.to_string() << std::endl;
}

