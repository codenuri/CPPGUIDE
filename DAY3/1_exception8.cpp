#include <iostream>
#include <mutex>
#include <thread>

// CP.20: Use RAII, never plain lock() / unlock()
// => 스택 풀기 기술 활용

// 항상 모든 자원의 할당/해지는  생성자 소멸자에 의존해야 합니다.
template<typename T>
class lock_guard
{
	T& m;
public:
	lock_guard(T& m) : m(m) { m.lock(); }
	~lock_guard() { m.unlock(); }
};
std::mutex m;

void foo()
{
	lock_guard<std::mutex> g(m); // RAII 기술!

//	m.lock();

	// 공유 자원 사용
	throw std::runtime_error("my exception");
	
//	m.unlock();
}

int main()
{
	std::thread t1(foo);
	std::thread t2(foo);

	t1.join();
	t2.join();
}