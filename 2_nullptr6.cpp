template<typename F, typename ARG>
void caller(F f, ARG arg) // std::nullptr_t arg = nullptr;
{					      
	f(arg);	// foo(arg) �ε�, arg �� std::nullptr_t �̹Ƿ�
			//				 ��� ������ Ÿ������ ���� ����.
}

void foo(int* p)
{
}

int main()
{
//	caller(foo, 0);			// error
	caller(foo, nullptr);	// ok
}