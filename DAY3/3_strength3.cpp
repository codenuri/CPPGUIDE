// checked_delete

#include <iostream>

// delete 할때 주의 할점
// 1. void* 를 delete 하지 마세요
// 2. incomplete type 을 delete 하지 마세요

class Object;	// 클래스 전방 선언
				// 전방선언만 있으면 포인터 변수를 생성가능합니다.
				// 불완전한(incomplete) 타입 이라고 합니다.
				// => delete 시에 소멸자가 호출되지 않은 문제가 있습니다.
void deleter(Object* p)
{
	// imcomplete type 은 크기를 구할수 없습니다.
	static_assert(sizeof(Object) > 0,
		"error, delete incomplete type");

	delete p;
}

struct Object
{
	Object()  { std::cout << "Object()" << std::endl; }
	~Object() { std::cout << "~Object()" << std::endl; }
};

/*
void deleter(Object* p)
//void deleter(void* p)
{
	delete p;
}
*/

int main()
{
	Object* p = new Object();
	deleter(p);
}