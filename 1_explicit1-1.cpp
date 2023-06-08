// 1_explicit1-1.cpp
#include <string>
#include <vector>

void f1(std::string s) {}
void f2(std::vector<int> v) {}

int main()
{
	f1("hello"); // ok.. 
				 // 생성자가 explicit 가 아니라는 의미
	 
	std::string s1("hello");  // ok
	std::string s2 = "hello"; // ok
					// string(const char* ) 생성자는 explicit 아님.

	f2(10); // error
	std::vector<int> v1(10);  // ok
	std::vector<int> v2 = 10; // error.
					// vector(int) 의 생성자는 explicit 라는 의미.
}
