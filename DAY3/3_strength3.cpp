// checked_delete

#include <iostream>

// delete �Ҷ� ���� ����
// 1. void* �� delete ���� ������
// 2. incomplete type �� delete ���� ������

class Object;	// Ŭ���� ���� ����
				// ���漱�� ������ ������ ������ ���������մϴ�.

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