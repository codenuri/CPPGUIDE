#include <string>

template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}

	template<typename U>
	Complex(const Complex<U>& c) : real(c.real), image(c.image) {}

	template<typename U> friend class Complex;
};

int main()
{
	Complex<std::string> c1("3", "2");
	Complex<int> c2 = c1;
}