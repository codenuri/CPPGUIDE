// nullptr �� ����
// 1. ���ʿ��� boost ���̺귯�� ���� ������� ����(boost.org)
// 
// 2. C++11 ���� ǥ�ؿ� ���Ե�. 
// => ǥ���� �Ʒ��� ���� ���������� �ƴ϶�, "Ű���� �Դϴ�.(true ����)"
// => ������ �ƴ� �� �Դϴ�.(rvalue)

void f1(int*  p) {}
void f2(char* p) {}

struct nullptr_t
{
	// �Ʒ� �Լ� ������ ��� ������ �����ͷ� �Ͻ��� ����ȯ �ɼ� �ֽ��ϴ�.
	template<typename T>
	operator T*() const { return 0; }

	// ����. C++11 ǥ���� bool ���� ����� ��ȯ�� ���
	explicit operator bool() const { return false; }
};
nullptr_t mynullptr;

int main()
{
	f1(mynullptr); // mynullptr => int*  ���� �Ͻ��� ��ȯ �ʿ�
	f2(mynullptr); // mynullptr => char* ���� �Ͻ��� ��ȯ �ʿ�
}