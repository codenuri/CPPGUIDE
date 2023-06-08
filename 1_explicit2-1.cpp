// 1_explicit2-1.cpp
// C++20 부터는 explicit(bool) 이 추가되었습니다.

template<typename T>
class Any
{
public:
	explicit(false) Any(const T& a) {}
};

int main()
{
	Any<int> a1 = 10;
	Any<double> a2 = 3.4;
}