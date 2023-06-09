#include <iostream>

// C.36 : A destructor must not fail
// C.37 : Make destructors noexcept
//			=> �Ҹ��ڴ� noexcept �� ǥ������ �ʾƵ� noexcept �Դϴ�.

class Object
{
public:
	~Object() 
	{
		std::cout << "~Object()\n";

		// �Ʒ� �ڵ�� ���� ����ϸ� �ȵ˴ϴ�.
		// �Ҹ��ڴ� ���ܸ� ������ �����ϴ�.
		//throw std::runtime_error("my exception");
	}
};

void foo()
{
	Object obj;
	throw std::runtime_error("my exception");
			// => ���ܰ� �߻��Ǿ ���������� �Ҹ��ڴ� �����ϰ� ȣ��˴ϴ�.
			// => ���� Ǯ��( stack unwinding ) �̶�� ���
			// => ��κ��� ��ü���� �� ������ Ư¡

	std::cout << "finish foo" << std::endl;
}

int main()
{
	try
	{
		foo();
	}
	catch (...)
	{
	}
}