// SL.con.1: Prefer using STL array or vector instead of a C array
// SL.con.2: Prefer using STL vector by default unless 
//           you have a reason to use a different container
// SL.con.3: Avoid bounds errors - [] vs at()

#include <iostream>
#include <array>
#include <vector>

// ������ ����� ���Ҵ� �Լ�. ���ڷ� �迭 �ּҿ� ������ �޴´�.
void foo(int* p, int sz) {}

int main()
{
	int x[10]          = { 1,2,3,4,5,6,7,8,9,10 }; // �迭�� ũ�� ���� �ȵ� 
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 }; // ũ�� ���� ����.

	// �迭 �� vector : ��� ���ӵ� �޸� ���.
	// ��, vector �� ũ�� ���氡��. 
	
	foo(x, 10); // �迭�� ���

	// foo �� vector ������
	//foo(&v, v.size()); // error

	foo(&v[0],    v.size()); // ok.. ������ ����ϴ� ���
	foo(v.data(), v.size()); // ok.. 

	// �迭    : ��� ��Ұ� stack �� �ִ�
	// vector : ��� ��Ұ� heap �� �ִ�.
	// std::array : raw array �� ������ ������ ����..
	//				������ ��� �Լ��� �����Ƿ� ���ϴ�.

	std::array<int, 5> arr = { 1,2,3,4,5 };

	int sz = arr.size();
}

template<typename T, int N>
struct array
{
	T buff[N];

	constexpr int size() const { return 5; }

};

