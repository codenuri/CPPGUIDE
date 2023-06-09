// R.22 : Use make_shared() to make shared_ptrs
// R.23 : Use make_unique() to make unique_ptrs

#include <iostream>
#include <memory>

void* operator new(std::size_t sz)
{
	std::cout << "new : " << sz << std::endl;
	return malloc(sz);
}

struct Point
{
	int x;
	int y;

	Point(int a, int b) : x(a), y(b) {}
};

int main()
{
	// 아래 코드는 몇번의 동적 메모리 할당이 있을까요 ?
	// 2번
	// 객체를 만들기 위한 new : new Point(1,2)
	// 관리객체를 만들기위해 new : shared_ptr 생성자에서.. 
//	std::shared_ptr<Point> sp1(new Point(1, 2));


	// 아래 코드는 위코드와 동일한 의미 이지만..
	// 좋은 코드입니다.
	// sizeof(Point) + sizeof(관리객체) 를 한번에 할당해서
	// 메모리 조각현상이 줄어들게 됩니다.
//	std::shared_ptr<Point> sp1 = std::make_shared<Point>(1, 2);


	// 장점 2. make_shared 가 안전합니다.
	// => C++ 에서 함수 인자가 평가되는 순서는 정의되어 있지 않습니다.
	
	// => 아래 코드가 (1), (2), (3) 의 순서로 실행되면 아무 문제 없습니다.
	// => 그런데, (1), (3), (2) 순서로 실행되고, (3) 에서 예외가 있다면 ??
	

	//			(2)	           (1)      (3)
//	foo(std::shared_ptr<int>(new int), goo());

	// 즉, 자원을 할당하면 즉시!!! 자원 관리 객체에게 넘겨야 합니다.
	// => 자원의 할당과 자원관리 객체의 생성은 동시(한번)에 이루어 져야 합니다.

	// std::make_shared<int>(0) : new int 하고 할당된 메모리를 0으로 초기화
	foo(std::make_shared<int>(0), goo());
}


void foo(std::shared_ptr<int> sp, int n) {}

int  goo() { return 10; }



