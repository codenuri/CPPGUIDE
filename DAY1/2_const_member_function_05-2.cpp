#include <iostream>

template<typename T> class vector
{
	T* buff;
	int size;
public:
	vector(int sz)
		: buff(new T[sz]), size(sz) {}

	~vector() { delete[] buff; }

	// [] �������� ���� const ������ non-const ��������
	// 2�� �����ϴ� ��찡 ��κ��Դϴ�
	T& operator[](int idx)       { return buff[idx]; }
	const T& operator[](int idx) const { return buff[idx]; }

	// �Ʒ� �ڵ�� ���� ?
	// const T& ��ȯ : buff[idx] �޸��� ������ ����� ��ȯ(lvalue)
	// T ��ȯ        : buff[idx] �� ���� ���� ��ȯ( rvalue)
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
	
	printf("%p\n", &v2[0]); // ��(T)��ȯ�ô� error
							// const T& ��ȯ�� ok
}