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
				// 1. �پ�� 2���� ���� �޸𸮴� ���ŵ����� �ʽ��ϴ�.
				// 2. �׷���, �Ҹ��ڸ� ȣ���ؼ� DB�� �ݾƾ� �մϴ�.
				//    ��, �Ҹ����� ����� ȣ���� �ʿ� �մϴ�.

	v.resize(4); // �þ �Ѱ��� ���� �޸𸮴� �̹� �ֽ��ϴ�.
				 // �����ڸ� �ٽ� ȣ���ؼ� DB �����ؾ� �մϴ�.
				 // => placement new �� �ʿ� �մϴ�
}
