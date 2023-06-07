class Test
{
public:
	void f1()        {}
	void f1() const {}

	// �� 2�� �Լ��� ������ �ǹ��� �Լ��� 
	// explicit object parameter  �� �����
	void f2(this Test& self) {}
	void f2(this const Test& self) {}

	// �ٽ� : const �� �Լ� �ڿ� ���� �ʰ�, �Լ� ����ȭ �Ǿ� �ֽ��ϴ�.
	// => ���ø��� ����ϸ� �� 2���� �Լ��� �ڵ����� �����մϴ�.
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