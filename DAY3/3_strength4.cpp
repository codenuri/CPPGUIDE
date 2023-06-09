// generic constructor
// => �������.. ���� �������� ����Դϴ�. 
// => �ѹ� ������ �θ�.. ���� ���������� ���ȴٴ� ���� �˰� �˴ϴ�.


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
	Complex<float>  c2 = c1; // ok.. ���� ������ ȣ��.. !

	Complex<double> c3 = c1; // error. c3 �� c1�� �ٸ� Ÿ���Դϴ�.
							// ���� �����ڴ� "���� Ÿ��" ������ ���˴ϴ�.
}