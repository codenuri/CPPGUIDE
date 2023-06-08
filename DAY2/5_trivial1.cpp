// SL.con.4: don’t use memset or memcpy for arguments that are 
//           not "trivially-copyable"

#include <iostream>

// trivial : special member function 이 하는 일이 
//				 "자명(널리 알려진 디폴트 방식대로 동작)" 하다는 의미.
// 
// special member function : 생성자, 소멸자, 복사(move) 생성자, 대입(move)연산자, 
// 
// trivial 생성자     : 아무 일도 하지 않은 생성자
// trivial 복사 생성자 : 모든 멤버를 얕은 복사하는 복사 생성자.

class A
{
};

// B의 생성자는 trivial 할까요 ?
class B 
{
	int data;
public:
	virtual void foo() {}
};

int main()
{
	B* p = static_cast<B*>(operator new(sizeof(B))); // 생성자 호출없이
													// 메모리만 할당
	p->foo(); // ?? 될까요 ?
}