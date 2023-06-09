// F.4: If a function might have to be evaluated at compile time, 
//      declare it constexpr
//
// F.5: If a function is very small and time - critical, declare it inline

template<typename T> 
[[nodiscard]] const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

template<typename T> 
[[nodiscard]] inline const T& max2(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

template<typename T> 
[[nodiscard]] constexpr const T& max3(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

int main()
{
	int ret1 = max1(1, 2); // ����ð��� ȣ��..
						   // call max1
	int ret2 = max2(1, 2); // ������ �ð��� max2 ���� ġȯ

	int ret3 = max3(1, 2); // ������ �ð��� �Լ� ����
						   // int ret3 = 2; �� ����� ����
							// ��, �̰��, ������ �ð��� �Ҽ��� �ְ�
							// ����ð��� �Ҽ��� �ֽ��ϴ�.

	constexpr int ret4 = max3(1, 2);  // �� ���� �׻� ������ �ð��� ����
}

// �׷�.. ��� �Լ��� constexpr �ϸ� ���� �ʳ��� ?
// => ȭ�� ���, �޸� �Ҵ�, ���� ������� ������ �ð��� �Ҽ� �����ϴ�.
// => ������ inline ġȯ�� �����մϴ�.



