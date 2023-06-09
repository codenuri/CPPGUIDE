#include <iostream>
#include <algorithm>
#include <vector>

// F.50 : Use a lambda(�Ǵ� �Լ���ü) when a function won't do 
//      (to capture local variables, or to write a local function)



// �Ϲ� �Լ� ������ main �� �ִ� �������� k�� ����Ҽ� �����ϴ�.
// => ĸ�� �ɷ� ����.
bool foo(int n) { return n % 3 == 0; }


class IsModulus
{
	int value;
public:
	IsModulus(int n) : value(n) {}

	bool operator()(int n) const
	{
		return n % value == 0;
	}
};

int main()
{
	std::vector<int> v = { 4,5,6,1,2,3,7,8,9,0 };

	int k = 3;

	IsModulus f(k); // f�� ���������� k�� ���� �����մϴ�.(���� ĸ���߽��ϴ�.)
	bool b = f(10); // 10 % k �� �ǹ�. ��, ĸ�ĵ� ������ ���� ����.

	auto ret1 = std::find_if(v.begin(), v.end(), f);
									//�Լ��� �������� k�� ���� �����ϴ� �ǹ�

	// �ѹ� ����Ѵٸ�.. �Ʒ� ó�� �ӽð�ü�� ���� ����ϸ� �˴ϴ�.
	// Ŭ�����̸�() : �ӽ÷� ����ϴ� ��ü ����

	auto ret2 = std::find_if(v.begin(), v.end(), IsModulus(k) );

}
