#include <iostream>
#include <type_traits>

// C90. memset, memcpy �� �������� ����!

class Test
{
	int data;
public:
	//virtual void foo() {}
};

// POD : C++11 ������ ���, class �� C�� ����ü�� ȣȯ�Ǵ°� ??

// C++11 ���Ĵ� �Ʒ� 2���� �� ���
// trivial : ��� �Լ��� �θ� �˷��� ��� �����ϴ°� ?
// 
// standard layout : �޸� ������ C ����ü�� �����Ѱ� ?
//					(�����Լ��� ����� �ϰ�, �����ڰ� ����� �մϴ�.)
//					(�����ڰ� ������ ���� �޸� �Ҵ��� �����ϹǷ�)

// POD = trivial + standard layout
// (Plain Old Data)





void init(Test* p)
{
	// Test �� �����Լ��� ������ �Ʒ� �ڵ�� �����Լ� ���̺� �����͵� 0���� ����
	// �ϰ� �˴ϴ�. 
	// class �� ���ؼ��� �ǵ��� memset ���� ������
	// ���� �ϰ� �ʹٸ�..
	static_assert(std::is_standard_layout_v<Test>,
					"error. Test is not standard layout");

	memset(p, 0, sizeof(Test));
}

int main()
{
	Test* p = new Test;

	init(p);
	p->foo();

	delete p;
}