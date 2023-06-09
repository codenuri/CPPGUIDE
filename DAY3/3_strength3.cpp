// checked_delete

#include <iostream>

// delete 할때 주의 할점
// 1. void* 를 delete 하지 마세요
// 2. incomplete type 을 delete 하지 마세요

class Object;	// 클래스 전방 선언
				// 전방선언만 있으면 포인터 변수를 생성가능합니다.

void deleter(Object* p)
{
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