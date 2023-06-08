// 1_explicit1-1.cpp
#include <string>
#include <vector>

void f1(std::string s) {}
void f2(std::vector<int> v) {}

int main()
{
	f1("hello"); // ok.. 
				 // �����ڰ� explicit �� �ƴ϶�� �ǹ�
	 
	std::string s1("hello");  // ok
	std::string s2 = "hello"; // ok
					// string(const char* ) �����ڴ� explicit �ƴ�.

	f2(10); // error
	std::vector<int> v1(10);  // ok
	std::vector<int> v2 = 10; // error.
					// vector(int) �� �����ڴ� explicit ��� �ǹ�.
}
