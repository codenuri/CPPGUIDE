class Point
{
	int x{ 0 };
	int y{ 0 };
public:
	explicit Point() = default;

	// ���ڰ� �Ѱ��� �ƴ� ���ų� ������ ��������
	// explicit �����մϴ�.
	explicit Point(int x, int y) : x{ x }, y{ y } {}
};

void fn(Point pt) {} // Point pt = {1,2}

int main()
{
	// C++11 ���ʹ� �Ʒ�ó�� �Լ� ���ڸ� �����ص� �˴ϴ�.
	// => ������ ���� ���˴ϴ�.
	fn( { 1,2 } );
	fn({}); // ����Ʈ �����ڰ� explicit �� �ƴϸ� ok
			// explicit ��� error
			// ������� �ʴ� ��찡 �����ϴ�.

}


