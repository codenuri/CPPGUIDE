template<typename F, typename ARG>
void caller(F f, ARG arg) // std::nullptr_t arg = nullptr;
{					      
	f(arg);	// foo(arg) 인데, arg 는 std::nullptr_t 이므로
			//				 모든 포인터 타입으로 전달 가능.
}

void foo(int* p)
{
}

int main()
{
//	caller(foo, 0);			// error
	caller(foo, nullptr);	// ok
}