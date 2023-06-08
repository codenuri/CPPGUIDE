// SL.con.4: don��t use memset or memcpy for arguments that are 
//           not "trivially-copyable"

#include <iostream>

// trivial : special member function �� �ϴ� ���� 
//				 "�ڸ�(�θ� �˷��� ����Ʈ ��Ĵ�� ����)" �ϴٴ� �ǹ�.
// 
// special member function : ������, �Ҹ���, ����(move) ������, ����(move)������, 
// 
// trivial ������     : �ƹ� �ϵ� ���� ���� ������
// trivial ���� ������ : ��� ����� ���� �����ϴ� ���� ������.

class A
{
};

// B�� �����ڴ� trivial �ұ�� ?
class B  // : public A
{
	int data;
//  A a;
public:
//	virtual void foo() {}
};

// �����ڰ� trivial �Ϸ���(��, �ƹ��ϵ� ���� ��������...)
// 1. �����Լ��� ����
// 2. ����ڰ� ���� �����ڰ� ����� �ϰ�
// 3. ��� Ŭ������ ���ų�, ��� Ŭ������ �����ڰ� trivial �ϰ�
// 4. ��ü�� ����� ���ų�, ��ü�� ����� �����ڰ� trivial �Ҷ�

// �����ڴ� trivial �ϴٰ� �մϴ�.


int main()
{
	B* p = static_cast<B*>(operator new(sizeof(B))); // ������ ȣ�����
													 // �޸𸮸� �Ҵ�

//	new(p) B;	// ����Ʈ ������ ȣ��

	p->foo();	// ?? �ɱ�� ?
}






