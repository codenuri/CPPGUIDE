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
}
