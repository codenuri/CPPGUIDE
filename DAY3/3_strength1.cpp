// ��� ������, �����ϰ� ���� �ڵ带 ���ؼ� �ʿ��� �����
// 1. [[nodiscard]]

template<typename T>
const T& max1(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

// [[ ]]  : attribute ����
//          C++ �����Ϸ����� �����ϴ� ����
template<typename T>
[[nodiscard]]
const T& max2(const T& lhs, const T& rhs)
{
	return lhs < rhs ? rhs : lhs;
}

int main()
{
	// �Լ� ȣ���� ����� ���� �ʰ� �ִ�..
	max1(1, 2);	
	max2(1, 2);
}