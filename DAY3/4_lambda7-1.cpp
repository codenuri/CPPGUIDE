
int main()
{
	auto swap1 = [](auto& a, auto& b) { auto c = a; a = b; b = c; };

	int    n1 = 10;
	double d1 = 3.4;

	swap1(n1, d1);	// �Ǵ°� ������� ? ������ ������� ?
					// ���� �ƴ�.
					// generic lambda(auto����)�� 2���� ���� �ٸ� ���ø��̹Ƿ�


	// C++20 ���� �߰��� "template lambda" ��� ����.
	auto swap2 = []<typename T>(T& a, T& b) { auto c = a; a = b; b = c; };

	swap2(n1, d1); // error
	swap2(n1, n1); // ok

}