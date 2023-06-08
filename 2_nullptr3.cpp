#include <iostream>
#include <thread>

void foo(int* p) {}

int main()
{
	// 1. foo 를 직접 호출할때는 인자로 0을 사용할수 있습니다.
	foo(0);

	// 2. foo 를 스레드로 수행할때 foo 인자로는 0을 사용할수
	//    없습니다.
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
		f(arg...); // 이 코드를 새로운 스레드로..
	}
};