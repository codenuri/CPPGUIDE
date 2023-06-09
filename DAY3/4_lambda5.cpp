// T.141: Use an unnamed lambda 
//        if you need a simple function object in one place only

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// F.10: If an operation can be reused, give it a name
// F.11 : Use an unnamed lambda 
//        if you need a simple function object in one place only


int main()
{
	// ���ٿ� Ÿ��

	// �ٽ� 1. ������ ������ ���� ǥ���� �Դϴ�. 
	// => ���� Ÿ���ϱ�� ? �ٸ� Ÿ���ϱ�� ?
	// => ����ǥ������ ��� �ٸ� Ÿ���Դϴ�.
	auto f1 = [](int a, int b) {return a + b; };
				// class xxx{ operator()(int, int) }; xxx();

	auto f2 = [](int a, int b) {return a + b; };
				// class yyy{ operator()(int, int) }; yyy();


	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;



	// �ٽ� 2. ������ ���� ǥ������ ������ ����ϴ� ���. <== �߿�
	std::vector<int> v = { 1,3,5,2,4,6 };

	// �Ʒ� ó�� �ڵ带 �ۼ��ߴٸ� sort() �Լ��� � �����Ǿ������ ?
	// => ��� ���� ǥ������ �ٸ� Ÿ���̹Ƿ�
	// => sort() �Լ��� 3�� �����˴ϴ�.
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b; });

	// �ذ�å : ������ ����ǥ������ ������ ���Ǹ� auto ������ ��Ƽ� ����ϼ���
	// => �Ʒ� ó�� ����� sort() �Լ��� �Ѱ� �� �����˴ϴ�.
	auto cmp = [](int a, int b) { return a < b; };
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);
	std::sort(v.begin(), v.end(), cmp);

	// ��, sort() ��ü�� inline �̶�� ��ó�� �ص� �˴ϴ�.
	// �ᱹ sort() �Լ��� �����Ǵ°��� �ƴ϶�, ����ϴ� ���� ġȯ �ǹǷ�
	// ��, �Ʒ� �ڵ�� ��� �����ϰ� �˴ϴ�.
}
