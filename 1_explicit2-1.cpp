// 1_explicit2-1.cpp
// C++20 부터는 explicit(bool) 이 추가되었습니다.
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