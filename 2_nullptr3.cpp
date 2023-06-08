#include <iostream>
#include <thread>

void foo(int* p) {}

int main()
{
	// 1. foo �� ���� ȣ���Ҷ��� ���ڷ� 0�� ����Ҽ� �ֽ��ϴ�.
	foo(0);

	// 2. foo �� ������� �����Ҷ� foo ���ڷδ� 0�� ����Ҽ�
	//    �����ϴ�.
//	std::thread t(&foo, 0); // error
	std::thread t(&foo, nullptr); // ok
	t.join();
}

class thread
{
public:
	template<typename F, typename ... T>
	thread(F f, T&& ... arg)
	{
		f(arg...); // �� �ڵ带 ���ο� �������..
	}
};