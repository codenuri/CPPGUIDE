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