// generic constructor
// => 어렵지만.. 아주 관례적인 기술입니다. 
// => 한번 이해해 두면.. 아주 여러곳에서 사용된다는 것을 알게 됩니다.


template<typename T>
class Complex
{
	T real, image;
public:
	Complex(const T& r, const T& i) : real(r), image(i) {}
};

int main()
{
	Complex<float>  c1(3.1f, 2.3f);
	Complex<float>  c2 = c1; // ok.. 복사 생성자 호출.. !

	Complex<double> c3 = c1; // error. c3 와 c1은 다른 타입입니다.
							// 복사 생성자는 "같은 타입" 에서만 사용됩니다.
}