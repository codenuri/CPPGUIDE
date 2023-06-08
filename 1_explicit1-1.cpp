// 1_explicit1-1.cpp
#include <string>
#include <vector>

void f1(std::string s) {}
void f2(std::vector<int> v) {}

int main()
{
	f1("hello");

	std::string s1("hello");
	std::string s2 = "hello";

	f2(10);
	std::vector<int> v1(10);
	std::vector<int> v2 = 10;
}
