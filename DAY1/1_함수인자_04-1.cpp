#include <iostream>
#include <string>

class Person
{
	std::string name;
	std::string address;
public:
	/*
	// ���ڰ� 2���� setter �� ���� move ����
	void set(const std::string& n, const std::string& a) 
	{ 
		name    = n; 
		address = a;
	}
	void set(std::string&& n, std::string&& a)
	{
		name    = std::move(n);
		address = std::move(a);
	}
	void set(std::string&& n, const std::string& a)
	{
		name = std::move(n);
		address = a;
	}
	void set(const std::string& n, std::string&& a)
	{
		name = n;
		address = std::move(a);
	}
	*/
	// ���ڰ� 2���� setter �� move �����Ϸ��� => 4���� �Լ� �ʿ�
	// ���ڰ� 3���� setter �� move �����Ϸ��� => 9���� �Լ� �ʿ�
	// �ٽ� : �� 4�� �Լ��� �ڵ������ǰ� �ؾ� �մϴ�.
	//      => T&& ���� ���(forwarding reference ��� ����)

	template<typename T1, typename T2>
	void set(T1&& n, T2&& a)
	{
		name = std::forward<T1>(n);
		addr = std::forward<T2>(a);
	}
};

int main()
{
	Person p;
	std::string s1 = "lee";
	std::string s2 = "seoul";

	p.set(s1, s2);
	p.set(s1, std::move(s2));

}