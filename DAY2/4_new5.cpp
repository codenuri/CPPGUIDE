#include <iostream>

class Point
{
	int x;
	int y;
public:
	// Point 는 디폴트 생성자가 없습니다.
	Point(int a, int b) : x(a), y(b) {}
	~Point() {}
};

// STL 의 vector 를 생각해 봅시다.
template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) : size(sz)
	{
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		for (int i = 0; i < size; i++)
		{
			new(&buff[i]) T; 
		}
	}
	vector(int sz, const T& value) : size(sz)
	{
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		for (int i = 0; i < size; i++)
		{
			new(&buff[i]) T(value); 
		}
	}
	~vector()
	{
		for (int i = 0; i < size; i++)
			buff[i].~T();
		operator delete(buff);
	}

	vector(const vector& other) : size(other.size)
	{
		// 1. 메모리 할당
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		// 2. other.buff 를 this->buffer 에 복사해야 합니다.
		//    최선의 코드는 ????
	}
};

int main()
{
	vector<Point> v1(5, Point(0, 0));

	vector<Point> v2 = v1; // 복사 생성자를 생각해 봅시다.
}