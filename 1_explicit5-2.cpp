// 1_explicit5-2.cpp
#include <iostream>

class Integer
{
	int value;
public:
	Integer(int n) : value(n) {}

	//operator int() { return value; }
	operator int() { return 100; }
};

int main()
{
	Integer n(10);

	// ����� ���� Ÿ���� cout ���� ����ϴ� ������ ������ ���ô�.
	// ��� 1. operator<<(ostream, Integer)  ������ ������ �������Լ� ����
	
	// ��� 2. std::cout  ���� ��� ������ Ÿ�������� ��ȯ ������ ����.

	std::cout << n << std::endl;
}

// delete cin �� cin << 5  �ڵ忡�� 
// void pointer ��ȯ�����ڰ� ȣ��Ǵ� �� �򰥸��µ���,

delete cin; // cin ��ü�� delete ������ Ÿ������ ��ȯ �������� ����
		    // operator void*() �� delete �����ϹǷ� ȣ������ ����� delete

cin << 5;   // cin �� << ������ �������� Ÿ������ ��ȯ �������� ����
			// operator bool() �� ������ ok
			// operator void*() �� �־ error.

// C++ : �����Ϸ��� ��ȯ�� �ʹ� ���� ����մϴ� (���� ����, ������ ����)
// �ٸ� ��� : ��ȯ�� �����մϴ�.

// C++ ���� ���Ǵ� ���
// "find_if �� 3��° ���ڷ� ���޵Ǵ� �Լ��� ��ȯŸ���� bool �̾�� �Ѵ�" ���ƴ϶�
// "find_if �� 3��° ���ڷ� ���޵Ǵ� �Լ��� ��ȯŸ���� bool �� ��ȯ �����ؾ� �Ѵ�."

// "operator void*() �� delete �����ϴ�" �� ������ �ΰ����谡 �� ���ص��� �ʽ��ϴ�.
// => C++ �������� void* �� delete �Ҽ� �ֽ��ϴ�.
void* p = new int;
delete p; // ��, �Ҹ��ڰ� ȣ����� �ʴ� ������ �־ �������Դϴ�.
          // �׷���, �������� �˴ϴ�.

