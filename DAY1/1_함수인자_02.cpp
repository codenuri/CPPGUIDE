// ���ڸ� �б⸸ �Ϸ��� �մϴ�.
// ������ ���� ���� ?
void good(int n)
{
	int local = n;
}

// �Ʒ� �ڵ尡 ���� ���� ���� 
void bad(const int& n)
{
	int local = n;
		// => ������ �ᱹ ������ �Դϴ�.
		// => �� �ڵ�� �ᱹ ���������� *p ������ ����˴ϴ�. 
}
// godbolt.org �� ������ ������.

int main()
{
	int n = 10;

	bad(n);
	good(n);
}