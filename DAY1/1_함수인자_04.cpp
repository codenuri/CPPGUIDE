#include <iostream>
#include <string>

class Person
{
	std::string name;
public:
	// 1. C++11 ���������� �Ʒ� �ڵ�� best �Դϴ�.
	//    ������ C++11 ���Ĵ� �����մϴ�.
//	void set_name(const std::string& n) { name = n; } // �ڿ��� �׻� ����
//	void set_name(const std::string& n) { name = std::move(n); } 
									// => �ڿ��� �׻� ����
									// => const ��ü�� move �ɼ� �����ϴ�.

	// ���, move�� �����Ϸ��� setter �� 2�� ������ �մϴ�
	void set_name(const std::string& n) { name = n; }
	void set_name(std::string&& n)      { name = std::move(n); }

	// �� �̰�쿡�� "string_view" �� ������� �ʳ��� ?
	// => �� ���� �ᱹ "name" ����� ���ڿ��� �����ϰ� �˴ϴ�.
	// => ��, ������ ���ڿ� ��ü�� ���� �ö󰡾� �մϴ�.
	// => �׷��� string_view �� �ƴ� const std::string& �� �ص� ��������ϴ�.
};

int main()
{
	Person p;

	std::string s = "lee";
	p.set_name(s);				// s�� ���ڿ��� ������ ����� ��
	p.set_name(std::move(s));	// s�� �ڿ��� �������� ���� ��������°�
	p.set_name("kim");
}