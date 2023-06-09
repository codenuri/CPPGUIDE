#include <iostream>
#include <string>

struct Resource
{
	Resource() { std::cout << "Resource()" << std::endl; }
	~Resource() { std::cout << "~Resource()" << std::endl; }
};
// �ٽ� 2. �ڿ��� ���� ���� ���� ����
//        �ڿ� ���� ��ü�� �����ض�   <== ���� C++ �� �ٽ�!!!
//			(new/delete �� ���� ������� ���� ��� ���̵�)
// => ����Ʈ �����͸� ����϶�� �ǹ�

// => ������ ȣ�⿡ ����(���� �߻�) �ϸ� �Ҹ��ڴ� ȣ����� ������
// => ����� ������ȣ���� ������ ���, ����� �Ҹ��ڴ� ȣ��˴ϴ�.
// => �ڿ� ������ ����Ʈ�����ͷ� �ϸ�, �׻� �ڿ��� �����ϰ� ���� �ȴٴ� �ǹ�
class Test
{
//	Resource* res;
	std::unique_ptr<Resource> res;
public:
	Test() : res(new Resource)
	{
		throw std::runtime_error("exception in constructor");
	}
	~Test()
	{
		std::cout << "~Test()" << std::endl;

//		delete res;
	}
};
int main()
{
	try
	{
		Test t;
	}
	catch (...) {}
}