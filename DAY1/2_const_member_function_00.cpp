// Con.1 : By default, make objects immutable
// "Con.2 : By default, make member functions const <=="
// Con.3 : By default, pass pointers and references to consts

int main()
{
	// �б⸸ �ϴ� ������� "���"�� ���弼��.
	// 1. ����� ��Ƽ�����忡 �����մϴ�.
	// 2. �����Ϸ� ����ȭ�� �ߵ˴ϴ�.
	// 3. �迭�� ũ�⳪, ���ø� ���ڷε� ��밡��
	// int max = 10;    // bad
	// const int max = 10; // good
	constexpr int max = 10; // good.
							// ��, ������ �ð��� �ʱⰪ�� �ƴ°�츸

	int score[max];
}