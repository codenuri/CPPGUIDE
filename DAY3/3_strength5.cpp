template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}

	// 복사 생성자 : 자신과 동일한 타입만 받을수 있다.
	// Complex<double> c3 = c1;  에서 T = double 이므로
	// 아래 코드는 Complex<double> 만 받을수 있는데..
	// c1은 Complex<float> 이므로 에러..
	// Complex(const Complex<T>& c) : real(c.real), image(c.image) {}

	// 아래 생성자는 인자로 "Complex<float>" 만 받을수 있습니다.
	// Complex<int> 등을 받을수는 없습니다.
	//Complex(const Complex<float>& c) : real(c.real), image(c.image) {}


	// 아래 코드가 "generic (copy) constructor" 라는 기술 입니다.
	// "U 가 T에 복사 (대입)될수 있다면
	// "Complex<U> 도 Complex<T>에 복사 될수 있어야 한다."

	template<typename U>
	Complex(const Complex<U>& c) : real(c.real), image(c.image) {}

	template<typename U> friend class Complex;
};

int main()
{
	Complex<float>  c1(3.1f, 2.3f);
	Complex<float>  c2 = c1; 

	Complex<double> c3 = c1; 
}