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
	// ����
	// v2 ��ü�� ��� �̰�, �Ҵ��� �޸�(����)�� ����� �ƴ�����
	// �ܺο��� ����ڰ� ����Ҷ��� ���۵� ��� ó�� ������ �մϴ�.

	// �Ʒ� 4���� �� ������ ������
	//			 ���ϴµ���	[]�� non-const  [] �� const
	n1 = v1[0]; // O		O				O
	n1 = v2[0]; // O		X				O

	v1[0] = 10; // O		O				O
	v2[0] = 10; // X		X				O
}