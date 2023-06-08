#include <iostream>
#include <type_traits> 

class Test
{
//	int data;
	int data = 0; // �� �ڵ�� �ᱹ �����ڿ��� �ʱ�ȭ �ϴ� �ڵ��Դϴ�
public:
//	virtual void foo() {} // �����Լ��� ������ non-trivial

//	Test() {}	// ����ڰ� �����ڸ� ���� non-trivial

	Test() = default; // = default �� ����� trivial
					  // ��, �ٸ� ���ǵ� �����Ҷ�
};

int main()
{
	// trivial ���θ� �����ϴ� ���
	bool b = std::is_trivially_default_constructible_v<Test>;

	std::cout << b << std::endl;
}
// �����ڰ� trivial �ϴٴ� ���� �ǹ�
// => ��ü�� �����Ҷ� ������ �����ڰ� ȣ����� �ʽ��ϴ�.
// => ���� �ڵ� ���� ������ ȣ���� �����Ǿ� �ֽ��ϴ�.