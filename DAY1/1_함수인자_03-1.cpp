#include <iostream>
#include <string>
#include <string_view>

// string_view
// => ���ڿ��� ���� �б� ���� view
int main()
{
	std::string s = "to be or not to be";

	std::string      ss = s; // ���ڿ��� �ڿ��� ����
	std::string_view sv = s; // s �� ���� ���ڿ��� ���
							// ��, s�� ���ڿ��� �뿩(borrow) �ؼ� ���
							// �ڽ��� �ڿ��� ���������� ����
							// sv �� ������ �Ѱ� + ���ڿ� ���̸� ����
	//-------------------------------------------------------------
	// �Ʒ� 2���� ���̵� ��Ȯ�� �˾� �μ���
	std::string      ss1 = "to be or not to be";
							// => ���� �Ҵ��ϰ� ���ڿ� ��ü�� ���� ����
	std::string_view sv1 = "to be or not to be";
							// => ��� �޸𸮿� �ִ� ���ڿ��� ����Ű�⸸ �Ѵ�

}