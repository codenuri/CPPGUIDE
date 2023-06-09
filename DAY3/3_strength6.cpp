#include <string>
#include <type_traits>

template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}

	/*
	template<typename U>
	Complex(const Complex<U>& c) : real(c.real), image(c.image) 
	{
	}
	*/

	// enable_if 기술 : 조건을 만족하지 않은 경우에는 템플릿을 사용하지 않게 하는 기술.
	// 현재 main 코드라면.. U : string   T : int

	// 왜 사용하나요 ?? => 안전하고, 에러가 이쁘게 출력 됩니다.!
	template<typename U,
			 typename = std::enable_if_t< std::is_convertible_v<U, T> >>

	Complex(const Complex<U>& c) : real(c.real), image(c.image)
	{
	}



	template<typename U> friend class Complex;
};

int main()
{
	Complex<std::string> c1("3", "2");

	Complex<int> c2 = c1;	// 빌드해서.. 에러 메세지 확인해 보세요.
}