// 2_nullptr5.cpp
#include <iostream>

int main()
{
	// nullptr : true, false ���� Ű���� �̰�..
	//			 ���ͷ�(��) �Դϴ�
	//			 rvalue �Դϴ�.
	// 
	// true, false : bool Ÿ��
	// nullptr     : std::nullptr_t Ÿ��

	// 1. nullptr Ÿ�� �˾� �μ���
	std::nullptr_t mynull = nullptr;

	// 2. ���� mynull �� nullptr ��� ��밡���մϴ�.
	int* p1  = mynull;
	char* p2 = mynull;
}