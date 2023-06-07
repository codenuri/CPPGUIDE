#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz)
		: buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	T& operator[](int idx) { return buff[idx]; }
};


int main()
{
	int n1 = 0;

	vector<int> v1(10);
	const vector<int> v2(10);

	// 아래 4줄을 잘 생각해 보세요
	//					원하는동작	현재 상태
	n1 = v1[0];
	n1 = v2[0];

	v1[0] = 10;
	v2[0] = 10;
}