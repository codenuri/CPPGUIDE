// ��ȯ�� ���輺.. �׸��� explicit 

// C++ ǥ�� ���̺귯���� std::cin �� ������ ���ô�.
class istream
{
	struct dummy
	{
		// �ּҸ� ����ϱ� ���� ���� �Լ�
		void true_function() {}
	};
public:
	bool fail() { return true; }

//	operator bool()  { return fail() ? false : true; }
//	operator void*() { return fail() ? 0     : this; }

	using F = void (dummy::*)();
	operator F () { return fail() ? 0 : &dummy::true_function; }
};
istream cin;

int main()
{
	// �Ʒ� ó�� if ������ cin �Է��� ��ȿ���� �����ϰ� �;���.
	if (cin) { }

	// ��� 1. bool ���� ��ȯ. 
	cin << 5; // �߸� ����ߴ�( >> �� �ؾ� �ϴµ� << �� ���)
			  // �׷���, ������ �ƴϴ�.
	// ��� 2. void* �� ��ȯ
	// => if() �� ���ϼ� �ְ�, cin << 5 �� ����!
	// => �׷���..
	delete cin; // �� �ڵ尡 ������ �ƴϴ�.
			    // C++98 ������ delete std::cin �� ������ �ƴ�.

	// ��� 3. boost ���̺귯�� ����.. ���� ������ ����� �����մϴ�.
	// => ��� �Լ��� �����ͷ��� ��ȯ
	// => "safe bool" �̶�� �Ҹ��� ���.

	// => ��ü�� if ���� ������ �ְ� �ϴµ�..
	// => side effect �� �ּ�ȭ �ؼ� ���׸� ���� ���
	// => "��� �Լ� ������"�� ��ȯ�� �ּ��̴�!! - C++98 ������ �ݾ�
}