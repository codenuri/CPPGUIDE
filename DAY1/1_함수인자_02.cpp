// 인자를 읽기만 하려고 합니다.
// 다음중 좋은 것은 ?
void good(int n)
{
	int local = n;
}

// 아래 코드가 좋지 않은 이유 
void bad(const int& n)
{
	int local = n;
		// => 참조는 결국 포인터 입니다.
		// => 위 코드는 결국 내부적으로 *p 등으로 변경됩니다. 
}
// godbolt.org 에 접속해 보세요.

int main()
{
	int n = 10;

	bad(n);
	good(n);
}