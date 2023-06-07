#include <iostream>
#include <string>
#include <string_view> // C++17 ���� ���� �˴ϴ�.
	
// ~ C++14 : const std::string& �� �ּ�
// C++17 ~ : std::string_view �� �ּ�

// �׷��ٸ� string �ܿ��� vector ���� ���ӵ� �޸𸮸� ����ϴ�
// �͵鿡 ���� view �� �ʿ� ���� ������� ?
// => C++20 ���� std::span �� ���ӵ� �޸𸮿� ���� view �Դϴ�.
//    string_view �� �Ϲ�ȭ ����... std::span<int> int_view;

// ���ϳ��� �߿��� ���� "�뿩(borrow)" �� �����Դϴ�.
// string      : �ڿ��� ����
// string_view : �ڿ��� �뿩


// std::string �� �б⸸ �ϴ� ���

void bad(std::string s)
{
}
void good(const std::string& s) {}

// �Ʒ� �ڵ尡 �ּ��� ���� �Դϴ�.
// std::string_view : call by value �� �޴� ���� ��Ģ
void best(std::string_view s) {}

int main()
{
	std::string s = "to be or not to be";

	bad(s);
	// �Ʒ� 2���� ��� ���� �մϴ�.
	good(s); // ������ �Ѱ�, ���ٽ� 2�� ����
	best(s); // ������ �Ѱ� + ����, ���ٽ� 1�� ����

	// �ٽ� : �Ʒ� 2���� ������ ������
	good("to be or not to be");
	best("to be or not to be");
}