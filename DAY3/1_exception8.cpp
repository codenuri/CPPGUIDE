#include <iostream>
#include <mutex>
#include <thread>

// CP.20: Use RAII, never plain lock() / unlock()
// => ���� Ǯ�� ��� Ȱ��

// �׻� ��� �ڿ��� �Ҵ�/������  ������ �Ҹ��ڿ� �����ؾ� �մϴ�.
// RAII ��� �̸��� ���
// => Resource Acquision Is (�ڿ����� ��ü�� ) Initialization
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
	lock_guard<std::mutex> g(m); // RAII ���!
							     // g�� �����ڰ� m.lock()

//	m.lock();

	// ���� �ڿ� ���
	throw std::runtime_error("my exception");
	
//	m.unlock();
}	// <== g �� �ı�, �Ҹ��ڿ� m.unlock()



int main()
{
	std::thread t1(foo);
	std::thread t2(foo);

	t1.join();
	t2.join();
}