
// F.53: Avoid capturing by reference in lambdas 
//       that will be used non - locally, 
//       including returned, stored on the heap, or passed to another thread

#include <vector>
#include <functional>
#include <vector>

std::function<int(int, int)> f;

void foo()
{
	int num = 10;
	f = [&num](int a, int b) { return a + b + num; };

} // <== �Լ� ȣ���� ���� �Ǿ����Ƿ� �������� "num" �ı�!!
  // <== ����ǥ���� "f" �� ���� reference ����� dangling reference �� �˴ϴ�.


void goo()
{
	int ret = f(1, 2); // 1 + 2 + num �ε�. num �� �̹� �ı���.
						// ������ ���� �߻�.. 
}

// ����ǥ������ ��ȯ�ϴ� �Լ�
// => �� ��쿡�� ���������� ���� ĸ������ ������.
auto hoo()
{
	int num = 10;
	return [&num](int a, int b) { return a + b + num; };
	
}


int main()
{
	foo();
	goo();


}