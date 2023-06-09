#include <iostream>
#include <string>

struct Resource
{
	Resource() { std::cout << "Resource()" << std::endl; }
	~Resource() { std::cout << "~Resource()" << std::endl; }
};

// �ذ�å 1. two phase initialization(constructor)
// => 2�� �ʱ�ȭ(������ ȣ��)�̶�� ���.

// �ٽ� : �����ڿ����� ���� ���ɼ��� ���� �ʱ�ȭ�� �Ѵ�
//       (���ܰ� �߻����� �ʴ� �ʱ�ȭ )
// => ������ �������� �ʱ� ������, �׻� �Ҹ��ڰ� ȣ��ȴٴ� ���� �����Ѵ�.

class Test
{
	int value;
	Resource* res;
public:
	Test() : value(0), res(nullptr)  {}

	// ���� ���ɼ��� �ִ� �ʱ�ȭ�� ������ ��� �Լ��� �����Ѵ�.
	void construct()
	{
		res = new Resource;

		throw std::runtime_error("exception in construct");
	}

	~Test()
	{
		delete res;
	}
};
int main()
{
	try
	{
		Test t;			// �ѹ�
		t.construct();	// �ι��� ���ļ� ��ü�� �ʱ�ȭ �˴ϴ�.
						// �׷��� 2�� �ʱ�ȭ(������ȣ��) ��� �̸� ���
	}
	catch (...) {}
}
// �Ｚ�� Ÿ����(������ �ٴ� OS)�̳� �Ϻ� ���¼ҽ����� ���� �ֽ��ϴ�.