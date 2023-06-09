
// 3_strength2 - 1.cpp
#include <iostream>

constexpr std::pair<int, bool> max(int a, int b)
{
//	std::cout << "max\n"; // �� �ڵ尡 ������ ������ �ð���
						  // ���� �ɼ� �����ϴ�.
//	bool b = std::is_constant_evaluated(); // C++20 

	return std::pair<int, bool>(a + b, std::is_constant_evaluated());
}

int main()
{
	// �Ʒ� ����� C++ �����Ϸ����� �ٸ��ϴ�. 
	//									cl�����Ϸ�
//	auto ret = max(1, 2);			// false
	
	const auto ret = max(1, 2);		// false 

//	constexpr auto ret = max(1, 2);	// true

	std::cout << ret.second << std::endl;
}