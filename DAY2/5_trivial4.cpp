#include <iostream>
#include <type_traits>

// C90. memset, memcpy 에 의존하지 말라!

class Test
{
	int data;
public:
	//virtual void foo() {}
};

// POD : C++11 이전의 용어, class 가 C의 구조체와 호환되는가 ??

// C++11 이후는 아래 2개의 용어를 사용
// trivial : 멤버 함수가 널리 알려진 대로 동작하는가 ?
// 
// standard layout : 메모리 구조가 C 구조체와 동일한가 ?
//					(가상함수가 없어야 하고, 생성자가 없어야 합니다.)
//					(생성자가 있으면 동적 메모리 할당이 가능하므로)

// POD = trivial + standard layout
// (Plain Old Data)





void init(Test* p)
{
	// Test 에 가상함수가 있으면 아래 코드는 가상함수 테이블 포인터도 0으로 변경
	// 하게 됩니다. 
	// class 에 대해서는 되도록 memset 하지 마세요
	// 만약 하고 싶다면..
	static_assert(std::is_standard_layout_v<Test>,
					"error. Test is not standard layout");

	memset(p, 0, sizeof(Test));
}

int main()
{
	Test* p = new Test;

	init(p);
	p->foo();

	delete p;
}