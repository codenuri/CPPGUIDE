// conversion function pointer

int main()
{
	// 람다표현식은 함수 포인터로도 변경가능합니다.
	// 
	// 단, 캡쳐하지 않은 람다 표현식만 함수 포인터 변환 가능합니다.

	int(*f1)(int, int) = [](int a, int b) { return a + b; };
					// class xxx{}; xxx(); 이므로 우변은 임시"객체"
					// "객체".operator 함수포인터() 라는 변환 연산자가 제공된다는것


	// 캡쳐한 람다 표현식은 함수포인터로 변환될수 없습니다.
	int num = 10;
	int(*f2)(int, int) = [num](int a, int b) { return a + b + num; };
						// error
				
}