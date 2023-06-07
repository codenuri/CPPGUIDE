#include <iostream>

// C.47: Define and initialize member variables 
//       in the order of member declaration

// 아래 클래스는 어떤 문제가 있을까요 ?
struct vector
{
	int* buff;
	int size;
public:
	// 핵심 : 초기화 리스트에 있는 코드의 실행순서는 미리 정의되있습니다.
	// 1. 기반 클래스 생성자가 먼저 실행되고
	// 2. 멤버의 생성자 실행
	// 3. 멤버의 생성자는 선언된 순서 대로 실행

	// 아래 코드의 실행순서 : (2)         (1) 
//	vector(int sz)       : size(sz), buff(new int[size])  // wrong
	vector(int sz)       : buff(new int[sz]), size(sz)   // good
	{
	}
	~vector()
	{
		delete[] buff;
	}
};
int main()
{
	vector v(10);
}