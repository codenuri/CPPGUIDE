

// T44. Use function templates to deduce class 
//      template argument types
//     

template<typename T> 
T square(T a)
{
	return a * a;
}

template<typename T> class List
{
public:
	List(int sz, T value) {}
};

// Ŭ���� ���ø��� ���� ����ϸ� Ÿ�� �߷��� ���� �ʱ� ������ ������ ���Դϴ�
// Ÿ���߷��� �ʿ��ϸ� �Լ� ���ø��� �����Լ��� ���弼��

template<typename T>
List<T> make_list(int size, T value)
{
	return List<T>(size, value);
}

int main()
{
	// ������ ���� ���̴� ���� ?
	square<int>(3);	// �� ǥ����� ��Ȯ�� ǥ���
	square(3);      // Ÿ������ ���� ����
					// �̰��, �Լ� ���ڸ� ���� T�� Ÿ���� �����Ϸ��� �߷�
					// Ÿ�� ������ ���� ���Դϴ�.

	// �Ʒ� �ڵ带 ������ ���ô�.
	List<int> s1(10, 3); // ��Ȯ�� ǥ��� - Ÿ�� ���� ����
//	List      s2(10, 3); // ������ ���ڸ� ���� Ÿ�� �߷� ??
						 // C++17 ���� ���� ����.
	auto s2 = make_list<int>(10, 3);
}







