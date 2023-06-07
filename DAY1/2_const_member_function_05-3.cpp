// 2_const_member_function_05-3.cpp
#include <vector>

int main()
{
	std::vector<int> v1 = { 1,2,3 };
	const std::vector<int> v2 = { 1,2,3 };

	// �����̸��� ������ const, non-const �Լ��� ���ÿ� �����ϴ�
	// ���� ���� �����ϴ�.
	auto p1 = v1.begin(); // iterator begin() {}
	auto p2 = v2.begin(); // const_iterator begin() const {}

	*p1 = 10; // ���� ������ �ݺ��� ( iterator )
	*p2 = 10; // ���� �Ұ����� �ݺ��� ( const_iterator )
}