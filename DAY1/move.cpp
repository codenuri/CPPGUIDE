// move.cpp
#include <iostream>
#include <string>

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	// C++11 ���� move ������ �����մϴ�.
	std::string s3 = s1;	// ��������� ȣ��
							// �ڿ��� ���� ����
							// ���ڿ� ��ü�� ����

	std::string s4 = std::move(s2);
							// �̵� ������ ȣ��
							// s2�� ���ڿ��� s4�� ���ҾƼ� ���

}