#include <iostream>

// C.47: Define and initialize member variables 
//       in the order of member declaration

// �Ʒ� Ŭ������ � ������ ������� ?
struct vector
{
	int* buff;
	int size;
public:
	// �ٽ� : �ʱ�ȭ ����Ʈ�� �ִ� �ڵ��� ��������� �̸� ���ǵ��ֽ��ϴ�.
	// 1. ��� Ŭ���� �����ڰ� ���� ����ǰ�
	// 2. ����� ������ ����
	// 3. ����� �����ڴ� ����� ���� ��� ����

	// �Ʒ� �ڵ��� ������� : (2)         (1) 
//	vector(int sz)       : size(sz), buff(new int[size])  // wrong
	vector(int sz)       : buff(new int[sz]), size(sz)   // good
	{
	}
	~vector()
	{
		delete[] buff;
	}
};
int main()
{
	vector v(10);
}