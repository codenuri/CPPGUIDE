#include <iostream>
#include <type_traits>

struct Point
{
	int x, y;
	Point() = default;
	Point(int a, int b) : x(a), y(b) {}

	// 1. 복사 생성자, 대입연산자등은 만들지 않는 것이 최선 입니다.
	// => 사용자가 만들지 않으면 컴파일러가 제공하므로!!

	// 2. 그런데, 사용자가 move 생성자 등을 만들면 컴파일러는
	//    복사 생성자를 제공하지 않습니다.

	Point(Point&& other)
		: x(std::move(other.x)), y(std::move(other.y)) {}

	// => 이 경우 "복사 생성자를 직접 구현하지 말고 = default"로 요청하세요
	
//	Point(const Point& p) : x(p.x), y(p.y) {} // non trivial
		
	Point(const Point& p) = default;		  // trivial
};


template<typename T>
void copy(T* dst, T* src, std::size_t size)
{
	if (std::is_trivially_copy_constructible_v<T>)
	{
		std::cout << "T의 복사 생성자는 trivial" << std::endl;
		memcpy(dst, src, sizeof(T) * size);
	}
	else
	{
		std::cout << "T의 복사 생성자는 non-trivial" << std::endl;

		while (size--)
		{
			new(dst) T(*src); // 복사 생성자 호출
			++dst, ++src;
		}
	}
}

int main()
{
	Point pt1[5] = { {1,1}, {2,2}, {3,3}, {4,4}, {5,5} };
	Point pt2[5];
	copy(pt2, pt1, 5);

}