#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz)
		: buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

//	T& operator[](int idx)       { return buff[idx]; }
	T& operator[](int idx) const { return buff[idx]; }
};


int main()
{
	int n1 = 0;

	vector<int> v1(10);
	const vector<int> v2(10);
	// 참고
	// v2 자체만 상수 이고, 할당한 메모리(버퍼)는 상수가 아니지만
	// 외부에서 사용자가 사용할때는 버퍼도 상수 처럼 보여야 합니다.

	// 아래 4줄을 잘 생각해 보세요
	//			 원하는동작	[]가 non-const  [] 가 const
	n1 = v1[0]; // O		O				O
	n1 = v2[0]; // O		X				O

	v1[0] = 10; // O		O				O
	v2[0] = 10; // X		X				O
}