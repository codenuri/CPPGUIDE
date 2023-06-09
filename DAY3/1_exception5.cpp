// F.6  : If your function must not throw, 
//        declare it noexcept

// noexcept Ű����
// 1. �Լ��� ���ܰ� �ִ��� �����Ҷ� ���
// 2. �Լ��� ���鶧 ���ܰ� ���ٰ� �����Ϸ� ���� �˷��ִ� ��
#include <iostream>

void f1() { }
void f2() noexcept { }

int main()
{
	// noexcept( �Լ�ȣ��� ) : "�Լ�ȣ���" ��� ���� ���ܰ��ɼ�
	//						  �� �ִ��� ����
	//				�Լ� ���� �ڿ� noexcept�� �پ� �ִ��� ����.
	bool b1 = noexcept( f1() );
	bool b2 = noexcept( f2() );

	std::cout << b1 << std::endl;
	std::cout << b2 << std::endl;
}