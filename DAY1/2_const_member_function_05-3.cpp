// 2_const_member_function_05-3.cpp
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3 };
	const std::vector<int> v2 = { 1,2,3 };

	// �����̸��� ������ const, non-const �Լ��� ���ÿ� �����ϴ�
	// ���� ���� �����ϴ�.
	auto p1 = v1.begin();
	auto p2 = v2.begin();

	*p1 = 10;
	*p2 = 10;
}