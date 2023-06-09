#include <vector>
#include <functional>
#include <vector>

int main()
{

	// ���� ǥ������ ��� ���
	// 1. auto ���� �� ��Ƽ� ���
	//    => �ѹ� �ʱ�ȭ ���Ŀ��� �ٸ� ���ٴ� ������ �����ϴ�.
	auto f1 = [](int a, int b) { return a + b; };
					// class AAA{}; AAA();

//	f1 = [](int a, int b) { return a + b; }; // error
					// class BBB{}; BBB() �̹Ƿ� �ٸ� Ÿ��


	// 2. std::function ���� ����ǥ������ ������ �ֽ��ϴ�.
	std::function<int(int, int)> f3 = [](int a, int b) { return a + b; };

	int ret = f3(1, 2);

	// f3 �� �ٸ� ���� ǥ����(�Ǵ� �Լ�, �Լ���ü)�� ������(����) �ֽ��ϴ�.
	f3 = [](int a, int b) { return a - b; };


	// 3. ������ ���ٸ� �����̳ʿ� �����Ҷ��� std::function ���� �ϸ� �˴ϴ�.

//	std::vector<auto> v1; // error
	
	std::vector<std::function<int(int, int)>> v2; // ok

	v2.push_back([](int a, int b) { return a - b; });
	v2.push_back([](int a, int b) { return a + b; });


	// ���� 1. ����ǥ���� �Ѱ��� ������ ��� ����Ҷ� 
	// => ������ auto ���!!
	auto f1 = [](int a, int b) {return a + b; }; // good

	std::function<int(int, int)> f2 = [](int a, int b) {return a + b; }; // bad

	int r1 = f1(1, 2); // ��κ� inline ġȯ �˴ϴ�.
	int r2 = f2(1, 2); // ��κ� inline ġȯ �ȵ˴ϴ�.

	// ���� 2. ����ǥ������ �����ؾ� �ϰų�, vector � �����Ҷ���
	// => function �ۿ� �ȵ˴ϴ�.
}