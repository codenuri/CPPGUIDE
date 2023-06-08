// ��ȯ ������ �� explicit �̾߱�
// explicit
// 1. �����ڿ� ���̱� - C++98 ���� ���� �ִ� ����
// 2. ��ȯ �����ڿ� ���̱� - C++11 ���� ����.
class Point
{
	int x;
	int y;
public:
	Point(int a, int b) : x(a), y(b) {}

	// ��ȯ ������ : ��ü�� �ٸ� Ÿ������ ��ȯ�ɶ� ���
	// Ư¡ : �Լ� �̸��� ��ȯ Ÿ���� ���ԵǾ� �ֽ��ϴ�.
	//       ����Ÿ���� ������ ǥ�� ���� �ʽ��ϴ�.
	explicit operator int() { return x; }
};

int main()
{
	Point pt(1, 2);


	int n = pt; // Point => int�� ��ȯ
				// pt.operator int() ��� �Լ� �� �ʿ�.
				// explicit �� ��� ����(�Ͻ��� ��ȯ �ȵ�)

	int n1 = static_cast<int>(pt); // ok..!
}