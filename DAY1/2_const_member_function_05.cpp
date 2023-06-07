#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) 
		: buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// [] 연산자 재정의 : 객체를 배열 처럼 사용할수 있게 한다.
	// 참조 반환 : "v[0] = 10" 처럼 함수 호출을 lvalue 에 놓을수있게 한다.
	T& operator[](int idx) { return buff[idx]; }
};


int main()
{
	int n1 = 0;

	vector<int> v(10);

	v[0] = 0;
	n1 = v[0];
}