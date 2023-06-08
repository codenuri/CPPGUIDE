template<typename F, typename ARG>
void caller(F f, ARG arg) // ARG arg = 0 인데.. 0은 정수 이므로
{					      // int arg = 0 으로 추론 됩니다.
	f(arg);
}

void foo(int* p)
{
}

int main()
{
	int n = 0;
	// 0 은 int 타입입니다. 그런데....
	foo(0);  // ok.     리터럴 0은 포인터로 암시적 변환 되지만
//	foo(n);  // error.  0을 가진 정수형 변수는 포인터로 
			//							암시적 변환 될수 없습니다.
	
	caller(foo, 0); // foo(0) 처럼 호출해 달라는 의도.
					// 하지만, error..
	caller(foo, nullptr); // ok. 
}