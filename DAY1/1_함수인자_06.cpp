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