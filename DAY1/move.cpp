// move.cpp
#include <iostream>
#include <string>

int main()
{
	std::string s1 = "to be or not to be";
	std::string s2 = "to be or not to be";

	// C++11 ���� move ������ �����մϴ�.
	std::string s3 = s1;
	std::string s4 = std::move(s2);
}