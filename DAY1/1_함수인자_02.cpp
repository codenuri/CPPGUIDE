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

// 정리
// 인자를 "읽기만(in parameter)" 한다면

// 1. 인자의 타입이 primitive(int, double 등 언어가 지원하는 기본 타입)
//    인경우
// => call by value!
// ex) good(int n);
// 
// 2. user define type : const reference
// ex) good(const Rect& r);