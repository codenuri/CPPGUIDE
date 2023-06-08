#include <iostream>
#include <vector>
#include <iterator>
#include <ranges>   // C++20 �� �ٽ� STL �߰�!!!

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8 };

	// �Ųٷ� �ٷκ��� view ���� �ٽ� 3���� ���� �ִ� view �� ����
	auto view = std::views::take( std::views::reverse(v), 3 );

	for (auto e : view )
	{
		std::cout << e << ", ";
	}
}
