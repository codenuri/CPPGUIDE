// C46.���ڰ� �Ѱ��� �����ڴ� explicit �� �ϴ� ���� ����.
// => ������ safety..

class Vector
{
public:
	// explicit ������ 
	// 1. ���� �ʱ�ȭ�� �����ϰ�, ���� �ʱ�ȭ�� ����Ҽ� ����.
	// 2. ��ȯ�� �뵵�� ���ɼ� ����.
	explicit Vector(int sz) {}
};

void fn(Vector v) {} // ���ڸ� �޴� ���� "Vector v = 10" �� �ڵ��Դϴ�.

int main()
{
	// �ٽ� 1. ���ڰ� �Ѱ��� �����ڰ� �ִٸ� �Ʒ� 4���� ���·�
	// ��ü ������ �����մϴ�.
	Vector v1(10);		// C++98  direct initialization
	Vector v2 = 10;		// C++98  copy   initialization
	Vector v3{ 10 };	// C++11  direct initialization
	Vector v4 = { 10 };	// C++11  copy   initialization

	// �ٽ� 2. ���ڰ� �Ѱ��� �����ڴ� ��ȯ�� �뵵�ε� ��밡���մϴ�.
	Vector v5(1);
	v5 = 10;	// int �� 10�� vector �� ��ȯ �����ؾ� �մϴ�.
				// 10 => Vector �� ��ȯ �Ǿ�� �Ѵ�.
				// 10�� �����ڷ� ������ Vector �ӽð�ü�� ������ v5�� ����

	// �ٽ� 3. ���� �ʱ�ȭ�� ������ ������ �ǰ��մϴ�.
	fn(10);
}




