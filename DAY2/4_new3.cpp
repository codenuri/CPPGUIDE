#include <iostream>
#include <vector>

/*
int main()
{
	std::vector<int> v(10);

	v.resize(7); // ���� ������ ������ ���ô�.
				 // �޸𸮴� ��� 10�� �̰�, size ������ 7��
				 // �޸� ���Ҵ� �ƴ�.

	std::cout << v.capacity() << std::endl; // 10
	std::cout << v.size() << std::endl; // 10
}
*/

class DBConnect {}; // �����ڿ��� DB ����
					// �Ҹ��ڿ��� DB �ݱ�

int main()
{
	std::vector<DBConnect> v(5);

	v.resize(3); // �̼����� ������ ���ô�.
}
