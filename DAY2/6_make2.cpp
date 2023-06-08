#include <iostream>
#include <tuple>
#include <vector>

int main()
{
	std::pair<int, double> p1(3, 3.4);
	std::tuple<int, double, int, double> t1(3, 3.4, 3, 3.4);

	// �� 2���� �Ʒ� 2�ٰ� ���� �մϴ�.
	auto p2 = std::make_pair(3, 3.4);
	auto t2 = std::make_tuple(3, 3.4, 3, 3.4);

	// �׷���, C++17 ���ʹ� �Ʒ� ó�� �ص� �˴ϴ�.
	std::pair p3(3, 3.4);
	std::tuple t3(3, 3.4, 3, 3.4);

	std::vector<int> v1 = { 1,2,3,4,5 };
	std::vector      v2 = { 1,2,3,4,5 }; // C++17 ����!!

}