// nullptr 의 원리
// 1. 최초에는 boost 라이브러리 팀에 만들었던 도구(boost.org)
// 
// 2. C++11 에서 표준에 도입됨. 
// => 표준은 아래와 같은 전역변수가 아니라, "키워드 입니다.(true 같은)"
// => 변수가 아닌 값 입니다.(rvalue)

void f1(int*  p) {}
void f2(char* p) {}

struct nullptr_t
{
	// 아래 함수 때문에 모든 종류의 포인터로 암시적 형변환 될수 있습니다.
	template<typename T>
	operator T*() const { return 0; }

	// 또한. C++11 표준은 bool 로의 명시적 변환도 허용
	explicit operator bool() const { return false; }
};
nullptr_t mynullptr;

int main()
{
	f1(mynullptr); // mynullptr => int*  로의 암시적 변환 필요
	f2(mynullptr); // mynullptr => char* 로의 암시적 변환 필요
}