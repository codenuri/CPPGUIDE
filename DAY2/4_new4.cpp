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
//		buff = new T; // 이렇게 하면 디폴트 생성자가 있는 타입만 저장 가능합니다.
		buff = static_cast<T*>( operator new(sizeof(T) * size) );

		for (int i = 0; i < size; i++)
		{
			new(&buff[i]) T; // 디폴트 생성자 호출.
		}
	}
	vector(int sz, const T& value) : size(sz)
	{
		buff = static_cast<T*>(operator new(sizeof(T) * size));

		for (int i = 0; i < size; i++)
		{
			new(&buff[i]) T(value); // 복사 생성자 호출. 
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
//	vector<Point> v(10);				// 디폴트 생성자로 10개 초기화
	vector<Point> v(10, Point(0,0) );	// Point(0,0) 객체를 복사해서 10개 초기화

}