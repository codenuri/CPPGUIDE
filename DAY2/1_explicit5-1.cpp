// 1_explicit5-1.cpp
class istream
{
public:
	bool fail() { return true; }

	// explicit ��ȯ ������
	// => �Ͻ��� ��ȯ�� �ȵǰ�, ����� ��ȯ�� ���
	explicit operator bool() { return fail() ? false : true; }
};
istream cin;
 
int main()
{
	bool b1 = cin;						// error
	bool b2 = static_cast<bool>(cin);	// ok.

	cin << 10;	// cin �� bool(int) �� �Ͻ��� ��ȯ�Ǹ� ok
				// ������ ������ ������� �����ϹǷ� error.

	if (cin) // �ٽ�.!!! if �� �ȿ����� ����� ĳ������ ��� ����.
	{
	}
}
// ���. if ( ��ü ) �� �ϰ� �ʹٸ�
// 1. C++11 ���� : "��� �Լ� ������" ���� ��ȯ�� �ּ��� ���
// 2. C++11 ���� : explicit operator bool() �� �ּ��� ���

