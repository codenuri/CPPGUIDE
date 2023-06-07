#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz) 
		: buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// [] ������ ������ : ��ü�� �迭 ó�� ����Ҽ� �ְ� �Ѵ�.
	// ���� ��ȯ : "v[0] = 10" ó�� �Լ� ȣ���� lvalue �� �������ְ� �Ѵ�.
	T& operator[](int idx) { return buff[idx]; }
};


int main()
{
	int n1 = 0;

	vector<int> v(10);

	v[0] = 0;
	n1 = v[0];
}