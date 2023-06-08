#include <iostream>
#include <type_traits>

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
		//buff = new T[size]; // 나쁜코드..	 메모리 할당 + 디폴트 생성자 호출
							// 그런데, 아래 코드에서 결국 복사생성(또는 memcpy)하게 됩니다.

		buff = static_cast<T*>(operator new(sizeof(T) * size));


		// 2. other.buff 를 this->buffer 에 복사해야 합니다.
		//    최선의 코드는 ????
		if (std::is_trivially_copy_constructible_v<T>)
		{
			memcpy(this->buff, &(other.buff), sizeof(T) * size); //???
		}
		else
		{
			for( int i =0 ; i < size; i++)
			{
				new(&buff[i]) T(other.buff[i]);
			}
		}
	}
};
// C++ 진영에서 가끔 아래 2개 용어를 듣게 됩니다.
// bitwise copy     : 위 코드에서 memcpy 버전
// member wise copy : 위 코드에서 아래 코드(각 멤버 별로 복사(복사 생성자 사용))




int main()
{
	vector<Point> v1(5, Point(0, 0));

	vector<Point> v2 = v1; // 복사 생성자를 생각해 봅시다.
}