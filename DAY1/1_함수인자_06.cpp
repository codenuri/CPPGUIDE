// 합과 차를 모두 반환하는 함수.
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
	int s2 = add_sub(1, 2, 0); // 포인터는 항상 null이 될수 있다는
								// 문제가 있습니다.

	int s3 = add_sub2(1, 2, out); // ok.. reference로 받으면
									// 항상 안전합니다.
}
// 결론 
// 1. out parameter 를 만들때는 포인터 보다 non-const reference
//    안전 합니다.

// 2. 포인터는 out parameter 의 의미가 아닌 "위치"의 의미 일때만 사용

// 총정리
// 1. 인자를 읽기만 하는 경우 - in parameter
// 
// => primitive 는 call by value : f1(int n)
// => UDT 는 call by const reference : f1(const Rect& r)

// => 문자열은 string_view : f1(std::string_view s);
// => 반복자는 call by value : f1( T iterator)

// 2. 인자를 쓰기도 하는 경우 - out parameter
// => non-const reference : f1(int& out)
// => 위치의 의미는 포인터   : f1(int* pos)

// 3. 인자값을 멤버에 보관하는 경우 - move 지원
// => 인자가 한개라면 2개의 setter 
//    set_name(const std::string& s) { name = s;}
//    set_name(std::string&& s) { name = std::move(s);}

// => 인자가 2개 이상이면 T&& 사용 4-1번 소스 참고.

// 4. 인자를 다른 함수에 전달하는 경우 - forwaring 파라미터
// => T&& 사용 - 5-1번 소스 참고.