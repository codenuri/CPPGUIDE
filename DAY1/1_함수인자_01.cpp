#include <iostream>

struct Rect
{
	int left, top, right, bottom;

	Rect(int x1, int y1, int x2, int y2) 
		: left(x1), top(y1), right(x2), bottom(y2)
};
// �ٽ� : call by value  vs  call by reference �̾߱�.

// ���ڸ� �б⸸ �Ұ��̶��
// 1. call by value
// ���� 1. ���纻�� ���� ���� ���
// ���� 2. ���� ������ȣ�⿡ ���� �������(�ڿ��� ����ϸ� �ڿ�����)
void bad1(Rect rc) {}

// 2. call by reference
// => ���纻 ���� ���ϰ�, ���� ������ ȣ�� �ȵ�
// ���� 1. �Լ� ���ο��� ��ü�� �����Ҽ� �ִ�. 
// ���� 2. �ӽð�ü�� ������ ����.
// => non-const reference �� "write" �뵵�϶��� ����ؾ� �մϴ�
void bad2(Rect& rc) {} 

void best(const Rect& rc) {}

int main()
{
	Rect rc = { 0, 0, 10, 10 };
	bad1(rc);
	bad2(rc); // ok
	bad2(Rect(0, 0, 10, 10)); // error. �ӽð�ü�� non-const ������ ������ ����

	best(rc);
	best(Rect(0, 0, 10,10));
}
