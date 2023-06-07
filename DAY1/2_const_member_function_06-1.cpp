class Test
{
public:
	void f1()        {}
	void f1() const {}

	// 위 2개 함수와 동일한 의미의 함수를 
	// explicit object parameter  로 만들면
	void f2(this Test& self) {}
	void f2(this const Test& self) {}

	// 핵심 : const 가 함수 뒤에 붙지 않고, 함수 인자화 되어 있습니다.
	// => 템플릿을 사용하면 위 2개의 함수를 자동생성 가능합니다.
	template<typename T>
	void f3(this T& self)
	{
	}
};

int main()
{
	const Test ct;
	ct.f1();
	ct.f2();
}