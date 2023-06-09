#include <iostream>
#include <string>

struct Resource
{
	Resource()  { std::cout << "Resource()" << std::endl; }
	~Resource() { std::cout << "~Resource()" << std::endl; }
};
// �ٽ� 1. ������ ȣ�⿡ ����(�����ڿ��� ���� �߻�)
//	      �Ҹ��ڰ� ȣ����� �ʽ��ϴ�.
// => �ڿ� ������ ���ɼ��� �ֽ��ϴ�. ( �Ʒ� �ڵ� ���� )
class Test
{
	Resource* res;
public:
	Test() : res(new Resource)
	{
		throw std::runtime_error("exception in constructor");
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
		Test t;
	}
	catch (...) {}
}