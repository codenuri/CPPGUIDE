#include <iostream>
#include <type_traits>

struct Point
{
	int x, y;
	Point() = default;
	Point(int a, int b) : x(a), y(b) {}

	// 사용자가 복사 생성자를 만든 경우 (얕은 복사로 구현해도...!!)
	// trivial 하지 않습니다.( 컴파일러는 세부 구현 방식 까지 확인할수는 없습니다.)
	// => 복사 생성자는 반드시 필요한 경우만 만드세요
	// => 사용자가 만드는 순간 trivial 하지 않게 됩니다.
	Point(const Point& p) : x(p.x), y(p.y) {} 
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

	// pt1 배열을 pt2 배열에 복사하는 함수를 만들어 봅시다.
	copy(pt2, pt1, 5);

}