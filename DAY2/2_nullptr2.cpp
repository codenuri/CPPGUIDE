template<typename F, typename ARG>
void caller(F f, ARG arg) // ARG arg = 0 �ε�.. 0�� ���� �̹Ƿ�
{					      // int arg = 0 ���� �߷� �˴ϴ�.
	f(arg);
}

void foo(int* p)
{
}

int main()
{
	int n = 0;
	// 0 �� int Ÿ���Դϴ�. �׷���....
	foo(0);  // ok.     ���ͷ� 0�� �����ͷ� �Ͻ��� ��ȯ ������
//	foo(n);  // error.  0�� ���� ������ ������ �����ͷ� 
			//							�Ͻ��� ��ȯ �ɼ� �����ϴ�.
	
	caller(foo, 0); // foo(0) ó�� ȣ���� �޶�� �ǵ�.
					// ������, error..
	caller(foo, nullptr); // ok. 
}