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
class B  // : public A
{
	int data;
//  A a;
public:
//	virtual void foo() {}
};

// 생성자가 trivial 하려면(즉, 아무일도 하지 않으려면...)
// 1. 가상함수가 없고
// 2. 사용자가 만든 생성자가 없어야 하고
// 3. 기반 클래스가 없거나, 기반 클래스의 생성자가 trivial 하고
// 4. 객체형 멤버가 없거나, 객체형 멤버의 생성자가 trivial 할때

// 생성자는 trivial 하다고 합니다.


int main()
{
	B* p = static_cast<B*>(operator new(sizeof(B))); // 생성자 호출없이
													 // 메모리만 할당

//	new(p) B;	// 디폴트 생성자 호출

	p->foo();	// ?? 될까요 ?
}






