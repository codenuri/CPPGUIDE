#include <iostream>
#include <vector>

/*
int main()
{
	std::vector<int> v(10);

	v.resize(7); // 구현 원리를 생각해 봅시다.
				 // 메모리는 계속 10개 이고, size 변수만 7로
				 // 메모리 재할당 아님.

	std::cout << v.capacity() << std::endl; // 10
	std::cout << v.size() << std::endl; // 10
}
*/

class DBConnect {}; // 생성자에서 DB 접속
					// 소멸자에서 DB 닫기

int main()
{
	std::vector<DBConnect> v(5);

	v.resize(3); // 이순간을 생각해 봅시다.
				// 1. 줄어든 2개를 위한 메모리는 제거되지는 않습니다.
				// 2. 그런데, 소멸자만 호출해서 DB는 닫아야 합니다.
				//    즉, 소멸자의 명시적 호출이 필요 합니다.

	v.resize(4); // 늘어난 한개를 위한 메모리는 이미 있습니다.
				 // 생성자만 다시 호출해서 DB 접속해야 합니다.
				 // => placement new 가 필요 합니다
}
