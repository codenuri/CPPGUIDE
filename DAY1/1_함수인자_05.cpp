#include <iostream>
#include <string>

// ���ڸ� �ٸ� �Լ��� �����ϴ� ���
// => ���ڸ� "forwarding" �Ѵ� ��� ǥ���մϴ�

// => ���纻�� ����� �ȵǰ�, const �� �߰� �Ǹ� �ȵ˴ϴ�.
// => int&, int&&, const int&, �׸��� volatile ���
//    �׸���, int �� �ƴ϶� ��� Ÿ�� ���..

// => �� ��� ��츦 �ڵ������ϱ� ���� template ���(T&&) ���
void f1(int  arg)  {}
void f2(int& arg) { arg = 100; }

template<typename F>
void forward_argument(F f, int& arg)
{
	f(arg);
}
template<typename F>
void forward_argument(F f, int&& arg)
{
	f(arg);
}
template<typename F>
void forward_argument(F f, const int& arg)
{
	f(arg);
}

int main()
{
	int n = 10;

	forward_argument(f1, 10);
	forward_argument(f2, n);
	const int c = 10;
	forward_argument(f1, c);
}


