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

// ����
// ���ڸ� "�б⸸(in parameter)" �Ѵٸ�

// 1. ������ Ÿ���� primitive(int, double �� �� �����ϴ� �⺻ Ÿ��)
//    �ΰ��
// => call by value!
// ex) good(int n);
// 
// 2. user define type : const reference
// ex) good(const Rect& r);