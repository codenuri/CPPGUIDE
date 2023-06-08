#include <iostream>
#include <vector>
#include <iterator>

int main()
{
	std::vector<int> v = { 1,2,3,4,5,6,7,8 };

	auto last = v.end(); // ������ ����


	// reverse �ݺ��� : ���ڷ� ���� �ݺ����� �Ѱ� ���� ����Ű��
	//					++����� --�� ����
	// last Ÿ�� : std::vector<int>::iterator 
//	std::reverse_iterator< std::vector<int>::iterator > rfirst( last ); // C++17����
//	std::reverse_iterator rfirst(last); // C++17 ����

	// C++17 ������ �����Լ��� ����ϸ� ���ø� ���� ��������
	auto rfirst = std::make_reverse_iterator(last);

	++rfirst; // �Ϲ� �ݺ����� -- �ǹ�

	std::cout << *rfirst << std::endl; // 7
}
// ���
// => �̹� C++ STL �ȿ��� make_ �� ����ؼ� Ŭ���� ���ø��� ��ü�� �����ϴ� ����
//    �Լ��� �ֽ��ϴ�.
// => �׷���, C++17 ���� ���ʹ� ���� ������ ������ �ֽ��ϴ�.!!