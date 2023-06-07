class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {  }

	// �ƹ� �ϵ� ���� ���� ����Ʈ �����ڸ� ����� ���
	
	// 1. ����ڰ� ���� �����. - bad
	// Point() {}

	// 2. �����Ϸ����� ��û�Ѵ�. - good
	Point() = default;

	// �׻� ����ڰ� ���� ����� �� ���ٴ� 
	// �����ϸ� �����Ϸ��� ����� ���� �����ϴ�.
};

int main()
{
	Point p1(1, 2); // ok

	Point p2; // ??
}