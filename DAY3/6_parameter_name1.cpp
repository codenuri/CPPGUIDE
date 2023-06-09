// F9. ������ ���� �Ķ���ʹ� �̸��� �־�� �ȵȴ�. 

#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

// �����ε��� ���� �뵵�θ� ���ȴٸ� empty Ŭ������ Ÿ���� ����
struct adopt_lock_t {};  // sizeof(adopt_lock_t) �� 1�Դϴ�.

adopt_lock_t adopt_lock;



template<typename T> class lock_guard
{
	T& mtx;
public:
	// �Ʒ� ó�� �ϸ� ����� ����ϹǷ� ����ð��� ���� �˴ϴ�
	/*
	lock_guard(T& m, bool lock = true) : mtx(m) 
	{
		if ( lock )
			mtx.lock(); 
	}
	*/
	// �Ʒ� ó�� �ϸ� ����ð� ������� �����ϴ�.
	// => �Լ� �����ε��� ������ �ð��� ������.
	lock_guard(T& m)                  : mtx(m) { mtx.lock(); }
	lock_guard(T& m, adopt_lock_t) : mtx(m) {  }

	~lock_guard() { mtx.unlock(); }
};


void foo()
{
//	lock_guard<std::mutex> g(m); // �����ڿ��� m.lock() ����

	// mutex �� lock �� �ٸ� ������� �����ߴ�.
	if ( m.try_lock() ) // �ٸ� ������� lock ȹ��
	{
		// lock �� �̹� ȹ��������, unlock �� �ڵ����� �ϰ� �ʹ�.
		// lock_guard<std::mutex> g(m); // ����, �����ڿ��� �ٽ� lock 

		//lock_guard<std::mutex> g(m, adopt_lock);
		std::lock_guard<std::mutex> g(m, std::adopt_lock);

		shared_data = 100;
		
	}

}


int main()
{

}