#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8 };

	auto last = v.end(); // ������ ����

	// reverse �ݺ��� : ���ڷ� ���� �ݺ����� �Ѱ� ���� ����Ű��
	//					++����� --�� ����
	std::reverse_iterator< ? > rfirst(last);

	++rfirst; // �Ϲ� �ݺ����� -- �ǹ�

	std::cout << *rfirst << std::endl;
}