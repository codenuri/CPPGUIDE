// Con.1 : By default, make objects immutable
// "Con.2 : By default, make member functions const <=="
// Con.3 : By default, pass pointers and references to consts

int main()
{
	// 읽기만 하는 변수라면 "상수"로 만드세요.
	// 1. 상수는 멀티스레드에 안전합니다.
	// 2. 컴파일러 최적화도 잘됩니다.
	// 3. 배열의 크기나, 템플릿 인자로도 사용가능
	// int max = 10;    // bad
	// const int max = 10; // good
	constexpr int max = 10; // good.
							// 단, 컴파일 시간에 초기값을 아는경우만

	int score[max];
}