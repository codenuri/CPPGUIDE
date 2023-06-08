// 1_explicit5-1.cpp
class istream
{
public:
	bool fail() { return true; }

	// explicit 변환 연산자
	// => 암시적 변환은 안되고, 명시적 변환만 허용
	explicit operator bool() { return fail() ? false : true; }
};
istream cin;
 
int main()
{
	bool b1 = cin;						// error
	bool b2 = static_cast<bool>(cin);	// ok.

	cin << 10;	// cin 이 bool(int) 로 암시적 변환되면 ok
				// 하지만 지금은 명시적만 가능하므로 error.

	if (cin) // 핵심.!!! if 문 안에서는 명시적 캐스팅이 없어도 가능.
	{
	}
}
// 결론. if ( 객체 ) 를 하고 싶다면
// 1. C++11 이전 : "멤버 함수 포인터" 로의 변환이 최선의 기술
// 2. C++11 이후 : explicit operator bool() 이 최선의 기술

