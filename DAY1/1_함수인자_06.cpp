// �հ� ���� ��� ��ȯ�ϴ� �Լ�.
int add_sub(int a, int b, int* out)
{
	int s = a + b;
	*out = a + b;
	return s;
}

int add_sub2(int a, int b, int& out)
{
	int s = a + b;
	out = a + b;
	return s;
}
int main()
{
	int out = 0;
	int s1 = add_sub(1, 2, &out);
	int s2 = add_sub(1, 2, 0); // �����ʹ� �׻� null�� �ɼ� �ִٴ�
								// ������ �ֽ��ϴ�.

	int s3 = add_sub2(1, 2, out); // ok.. reference�� ������
									// �׻� �����մϴ�.
}
// ��� 
// 1. out parameter �� ���鶧�� ������ ���� non-const reference
//    ���� �մϴ�.

// 2. �����ʹ� out parameter �� �ǹ̰� �ƴ� "��ġ"�� �ǹ� �϶��� ���

// ������
// 1. ���ڸ� �б⸸ �ϴ� ��� - in parameter
// 
// => primitive �� call by value : f1(int n)
// => UDT �� call by const reference : f1(const Rect& r)

// => ���ڿ��� string_view : f1(std::string_view s);
// => �ݺ��ڴ� call by value : f1( T iterator)

// 2. ���ڸ� ���⵵ �ϴ� ��� - out parameter
// => non-const reference : f1(int& out)
// => ��ġ�� �ǹ̴� ������   : f1(int* pos)

// 3. ���ڰ��� ����� �����ϴ� ��� - move ����
// => ���ڰ� �Ѱ���� 2���� setter 
//    set_name(const std::string& s) { name = s;}
//    set_name(std::string&& s) { name = std::move(s);}

// => ���ڰ� 2�� �̻��̸� T&& ��� 4-1�� �ҽ� ����.

// 4. ���ڸ� �ٸ� �Լ��� �����ϴ� ��� - forwaring �Ķ����
// => T&& ��� - 5-1�� �ҽ� ����.