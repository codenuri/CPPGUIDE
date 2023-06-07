// ��� ��� �Լ��� ������ �ƴ� �ʼ� �Դϴ�.
// => �Ʒ� get_area() �� �ݵ�� ��� ����Լ��� �߾�� �մϴ�.

// ��ü�� ���¸� �������� ���� ��� ����Լ�(getter) ��
// 
// "�ݵ��" ��� ��� �Լ��� �Ǿ�� �մϴ�.
class Rect
{
	int x, y, w, h;
public:
	Rect(int x, int y, int w, int h) : x{ x }, y{ y }, w{ w }, h{ h } {}

	//int get_area() { return w * h; } // wrong
	int get_area() const { return w * h; } // good!
};

//void foo(Rect r) // call by value => ���纻 ����, ���� �ڵ�!!
void foo(const Rect& r) // good
{
	int n = r.get_area(); // ???
}

int main()
{
	Rect r(1, 2, 3, 4);   // ��� ��ü �ƴ�..
	int n = r.get_area(); // ok. 
	foo(r);
}