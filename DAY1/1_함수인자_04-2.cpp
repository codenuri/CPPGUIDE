#include <iostream>
#include <string_view>
#include <string>
#include <array>

class Person
{
	std::string name;
	std::string address;
	std::array<int, 32> data;
public:
	// move �� ����ϴ� ��� : ���ڷ� ���� ���� ����� �����Ҷ�(��, setter)
	
	// �׿ܴ� ��� ���ʿ� �����ϴ�.

	// 1. ���ڷ� ���� ���� ����� �������� �ʰ�
	//    �Լ� ���������� ��븸 �Ҷ�
	// => move ��� ��� �ƴմϴ�.
	//void print_msg(const std::string& msg) // good
	void print_msg(std::string_view msg)     // best
	{
		std::cout << msg << std::endl;
	}

	// 2. move �� ���� �Ҵ��� ����ϴ� Ÿ�Կ����� ��������� �ֽ��ϴ�
	//    Ư�� Ÿ���� move �� ������ ���� ��찡 �ֽ��ϴ�.
	// => �Ʒ� �ڵ�� ���ڸ� ��� �� ����������
	// => std::array ��ü�� move ���� ��������� ȿ���� �����ϴ�.
	void set_data(const std::array<int, 32>& d)
	{
		data = d;
	}
};

int main()
{
	Person p;

	std::string s = "to be or no to be";
	std::array<int, 32> arr = { 0 };

	p.print_msg(s);
	p.set_data(arr);
}