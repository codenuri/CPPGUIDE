#include <iostream>

// C150. �����Լ������� ���� ����Ʈ ���ڸ� �������� ����(������� ������ �� ����.)

class Base
{
public:
	virtual void foo(int a = 10) { std::cout << "Base : " << a << std::endl; }
};
class Derived : public Base
{
public:
	virtual void foo(int a = 20) { std::cout << "Derived : " << a << std::endl; }
};

int main()
{
	Base* p = new Derived;
	p->foo();   // �������� ���� ��� ������ ������
				// "Derived : 10"

	// �����Լ� : p �� Ÿ���� Base* ��, ������ Base ���� ȣ������ �ʰ�
	//			 ����ð��� p�� ����Ű�� ���� �����ؼ� �Լ��� ����
	// 
	// ����Ʈ ���� : �����Ϸ��� ������ �ð��� ä��� �ȴ�.
	//		       �����Ͻð����� p�� Ÿ�Ը� �˼� �ִ�.

	p����Ű�� ���� ����ð��� ������ ������ ��ü�� Ÿ���� ->foo(
						    �����Ϸ��� �߰��� ����Ʈ �� 10 );
}
// �� �ݾ��� �ٽ�
// => � ������ ������ �ð��� �����ϴ���, ����ð��� �����ϴ��� �����ϼ���
// �����Լ�   : ����ð��� �Լ��� ����
// ����Ʈ ���� : ������ �ð��� ä���ش�.

// �ǵ��� ����ð� ������ ������ �ð� ������ ��� ������� ������
// => �����Լ��� ����Ʈ ���� ����..