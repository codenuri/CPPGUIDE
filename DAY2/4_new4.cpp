#include <iostream>

class Point
{
	int x;
	int y;
public:
	// Point �� ����Ʈ �����ڰ� �����ϴ�.
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

// STL �� vector �� ������ ���ô�.
template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : size(sz)
	{
//		buff = new T; // �̷��� �ϸ� ����Ʈ �����ڰ� �ִ� Ÿ�Ը� ���� �����մϴ�.
		buff = static_cast<T*>( operator new(sizeof(T) * size) );

		for (int i = 0; i < size; i++)
		{
			new(&buff[i]) T; // ����Ʈ ������ ȣ��.
		}
	}
	vector(int sz, const T& value) : size(sz)
	{
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		for (int i = 0; i < size; i++)
		{
			new(&buff[i]) T(value); // ���� ������ ȣ��. 
		}
	}
	~vector()
	{
		for (int i = 0; i < size; i++)
			buff[i].~T();
		operator delete(buff);
	}
};

int main()
{
//	vector<Point> v(10);				// ����Ʈ �����ڷ� 10�� �ʱ�ȭ
	vector<Point> v(10, Point(0,0) );	// Point(0,0) ��ü�� �����ؼ� 10�� �ʱ�ȭ

}