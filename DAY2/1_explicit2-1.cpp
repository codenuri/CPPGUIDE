// 1_explicit2-1.cpp
// C++20 ���ʹ� explicit(bool) �� �߰��Ǿ����ϴ�.
#include <type_traits>

template<typename T>
class Any
{
public:
	explicit( std::is_integral_v<T> ) Any(const T& a) {}
};

int main()
{
//	Any<int> a1 = 10; // error
	Any<int> a2( 10); // ok

	Any<double> a3 = 3.4; // ok
}