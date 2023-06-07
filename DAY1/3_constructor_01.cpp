#include <string>

// �ٽ� : ��� ����Ÿ�� �ʱ�ȭ �Ҷ��� 
//       �׻� �ʱ�ȭ ����Ʈ�� �����ϴ�.

class People1
{
	std::string name;
	int age;
public:
	People1(const std::string& s, int a) 
		: name(s), age(a)		// good
	{							// name �� ���ؼ�
								// string(const string&s) ���� ������
								// 1ȸ ȣ��� �ʱ�ȭ.!
	}
};

class People2
{
	std::string name;
	int age;
public:
	// ����� �ڵ�							// �����Ϸ� �߰� �ڵ�
	People2(const std::string& s, int a)	// : name() 
	{										
		name = s;	// bad.
					// 1. name �� ����Ʈ �����ڰ� ȣ�����
					// 2. ���Կ����� (name.operator=(s)) �� �� ����
					// ��, 2���� �Լ� ȣ�� �߻�
		age = a;
	}
};

int main()
{
	std::string s = "john";
	People1 p1(s, 20);
	People2 p2(s, 20);
}

// ���� string �� alias �Դϴ�. ���� Ŭ������ "basic_string �Դϴ�.
/*
using string = std::basic_string<char,
							std::char_traits<char>,
							std::allocator<char>>;
							*/