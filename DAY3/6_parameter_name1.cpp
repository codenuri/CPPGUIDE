// F9. 사용되지 않은 파라미터는 이름이 있어서는 안된다. 

#include <iostream>
#include <mutex>

std::mutex m;
int shared_data = 0;

// 오버로딩을 위한 용도로만 사용된다면 empty 클래스로 타입을 설계
struct adopt_lock_t {};  // sizeof(adopt_lock_t) 는 1입니다.

adopt_lock_t adopt_lock;



template<typename T> class lock_guard
{
	T& mtx;
public:
	// 아래 처럼 하면 제어문을 사용하므로 실행시간이 낭비 됩니다
	/*
	lock_guard(T& m, bool lock = true) : mtx(m) 
	{
		if ( lock )
			mtx.lock(); 
	}
	*/
	// 아래 처럼 하면 실행시간 오버헤드 없습니다.
	// => 함수 오버로딩은 컴파일 시간에 결정됨.
	lock_guard(T& m)                  : mtx(m) { mtx.lock(); }
	lock_guard(T& m, adopt_lock_t) : mtx(m) {  }

	~lock_guard() { mtx.unlock(); }
};


void foo()
{
//	lock_guard<std::mutex> g(m); // 생성자에서 m.lock() 수행

	// mutex 의 lock 을 다른 방법으로 수행했다.
	if ( m.try_lock() ) // 다른 방법으로 lock 획득
	{
		// lock 을 이미 획득했지만, unlock 은 자동으로 하고 싶다.
		// lock_guard<std::mutex> g(m); // 버그, 생성자에서 다시 lock 

		//lock_guard<std::mutex> g(m, adopt_lock);
		std::lock_guard<std::mutex> g(m, std::adopt_lock);

		shared_data = 100;
		
	}

}


int main()
{

}