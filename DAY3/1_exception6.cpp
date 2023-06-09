#include <iostream>
#include <vector>

// noexcept �� ���̴� ����
// 1. �����Ϸ��� ���� ȿ������ ���� �ڵ带 �����մϴ�.
// 
// 2. ���̺귯�� ���ο��� noexcept �� ���� ���� ���� ���� ��쿡
//    �ٸ��� ó���ϴ� ��찡 �ֽ��ϴ�.

// move �迭 �Լ��� noexcept �� ������ �Ѵ�.

class Object
{
public:
	Object() {}
	Object(const Object&) { std::cout << "copy ctor" << std::endl; }
	Object(Object&&)  noexcept    { std::cout << "move ctor" << std::endl; }
};

int main()
{
	std::vector<Object> v(5);

	std::cout << "----------------" << std::endl;

	// vector �� ���������� Object �� move �����ڸ� �����ؼ�
	// ���ܰ� ���ٸ� : move ������ ���
	// ���ܰ��ɼ��� �ִٸ� : copy ������ ���

	// Object �� move �������� ���� ���δ� : ����ڰ� �˷���� �մϴ�.
	//								move ������ �ڿ� noexcept ǥ��
	v.resize(10); // �̼����� ������ �����غ��ô�.

	std::cout << "----------------" << std::endl;
}

// GUIDE : �Լ��� ���ܰ� ������ �����Ҽ� �ִٸ� noexcept ���̼���
// �׷���, ���� �ʽ��ϴ�.
// 1. move ������, move ���Կ����ڴ� �ݵ�� noexcept ���̼���
// 2. �ڿ� ���� �Լ����� �� noexcept ���̼���
// 3. �Ҹ��ڴ� ����Ʈ�� noexcept

// �׿ܿ��� Ȯ���� ������ ������ ������.

// ���ܰ� �������� ��ư� �����մϴ�.
// => �׷��� rust �� ���ܰ� �����ϴ�..