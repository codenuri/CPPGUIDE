// conversion function pointer

int main()
{
	// ����ǥ������ �Լ� �����ͷε� ���氡���մϴ�.
	// 
	// ��, ĸ������ ���� ���� ǥ���ĸ� �Լ� ������ ��ȯ �����մϴ�.

	int(*f1)(int, int) = [](int a, int b) { return a + b; };
					// class xxx{}; xxx(); �̹Ƿ� �캯�� �ӽ�"��ü"
					// "��ü".operator �Լ�������() ��� ��ȯ �����ڰ� �����ȴٴ°�


	// ĸ���� ���� ǥ������ �Լ������ͷ� ��ȯ�ɼ� �����ϴ�.
	int num = 10;
	int(*f2)(int, int) = [num](int a, int b) { return a + b + num; };
						// error
				
}