#include <iostream>

int main()
{
	int n = 0;

	std::cin >> n; // ���� "a" �� �Է� �Ѵٸ� ?
					// �Է� ����, n�� ��ȭ ����.

	std::cout << n << std::endl; // 0.. 
		// 1. 10      2. 0     3. -1     4. 97

	// �Է� ����/���� ���θ� �����ϴ� ���
	// 1. fail() ��� �Լ� ���..
	if (std::cin.fail()) {}

	// 2. ��ü�� scalar test ���..(��ü�� if �� �ֱ�)
	if (std::cin)   // C++98 : cin.operator void*()
	{				// C++11 : cin.operator bool()
		// ����..
	}


}