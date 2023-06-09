template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}

	// 복사 생성자 : 자신과 동일한 타입만 받을수 있다.
	Complex(const Complex<T>& c) : real(c.real), image(c.image) {}
};

int main()
{
	Complex<float>  c1(3.1f, 2.3f);
	Complex<float>  c2 = c1; 

	Complex<double> c3 = c1; 
}