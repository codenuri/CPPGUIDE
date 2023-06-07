#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz)
		: buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// [] 연산자의 경우는 const 버전과 non-const 버전으로
	// 2개 제공하는 경우가 대부분입니다
	T& operator[](int idx)       { return buff[idx]; }
	const T& operator[](int idx) const { return buff[idx]; }

	// 아래 코드는 어떨까요 ?
	// const T& 반환 : buff[idx] 메모리의 별명을 상수로 반환(lvalue)
	// T 반환        : buff[idx] 가 가진 값을 반환( rvalue)
	// T operator[](int idx) const { return buff[idx]; }
};
int main()
{
	int n1 = 0;

	vector<int> v1(10);
	const vector<int> v2(10);
	//			 
	n1 = v1[0]; // O		
	n1 = v2[0]; // O	

	v1[0] = 10; // O	
//	v2[0] = 10; // X	
	
	printf("%p\n", &v2[0]); // 값(T)반환시는 error
							// const T& 반환은 ok
}